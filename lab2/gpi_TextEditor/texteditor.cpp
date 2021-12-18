#include "texteditor.h"
#include "ui_texteditor.h"

TextEditor::TextEditor(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(gpi_documentModified()));
    this->setWindowTitle("gpi_TextEditor[*]");

    QVariant gpi_variant = QSettings(this).value("gpi_VIEWF");
    QFont gpi_font = gpi_variant.value<QFont>();
    ui->textEdit->setFont(gpi_font);

    //connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(gpi_on_actionAbout_triggered())); //on_actionAbout_triggered()
    connect(ui->actionAboutQt, SIGNAL(triggered()), this, SLOT(gpi_on_actionAboutQt_triggered()));
    connect(ui->actionCopy, SIGNAL(triggered()), this, SLOT(gpi_on_actionCopy_triggered()));
    connect(ui->actionCut, SIGNAL(triggered()), this, SLOT(gpi_on_actionCut_triggered()));
    connect(ui->actionPaste, SIGNAL(triggered()), this, SLOT(gpi_on_actionPaste_triggered()));
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(gpi_on_actionUndo_triggered()));
    connect(ui->actionRedo, SIGNAL(triggered()), this, SLOT(gpi_on_actionRedo_triggered()));

    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionRedo->setEnabled(false);
    ui->actionUndo->setEnabled(false);

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(gpi_saveFile()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(gpi_saveFileAs()));

    gpi_loadFile(fileName);
}

TextEditor::~TextEditor()
{
    delete ui;
}


void TextEditor::on_actionNew_triggered()
{
    TextEditor* t = new TextEditor();
    t->show();
}


void TextEditor::on_actionClose_triggered()
{
    close();
}


void TextEditor::on_actionExit_triggered()
{
    qApp->closeAllWindows();
}

void TextEditor::gpi_documentModified()
{
    setWindowModified(true);
}

void TextEditor:: closeEvent(QCloseEvent *e)
{
    if (!isWindowModified()) {
        return;
    }

    int gpi_case = QMessageBox::warning(this, // родитель
                                        "Документ изменен", // заголовок
                                        "Документ был изменен, вы хотите закрыть его?" // Сообщение
                                        "\n"
                                        "Вы потеряете все изменения.",
                                        QMessageBox::Yes // Кнопки
                                        | QMessageBox::No
                                        | QMessageBox::Cancel,
                                        QMessageBox::Cancel // Кнопка выделенная (кнопка по умолчанию)
                                        );
    switch(gpi_case)
    {
        case(QMessageBox::Yes):
            gpi_saveFile();
            e->accept();
            break;
        case(QMessageBox::No):
            e->ignore();
            break;
        case(QMessageBox::Cancel):
            e->ignore();
            break;
    }
}

void TextEditor::on_actionSelectFont_triggered()
{
   // QFont q = QFontDialog::getFont(*ok, initial, parent);
    bool ok;
    QFont gpi_newFont = QFontDialog::getFont(&ok, this);
    if (ok) {
        ui->textEdit->setFont(gpi_newFont);
        QSettings settings(this);
        settings.setValue("gpi_VIEWF", gpi_newFont);
    }
}

void TextEditor::gpi_on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}

void TextEditor::gpi_on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void TextEditor::gpi_on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void TextEditor::gpi_on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void TextEditor::gpi_on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void TextEditor::gpi_on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void TextEditor::on_actionAbout_triggered()
{
    QString str =
            "Разработчик: \n"
            "    студент 3-его курса \n"
            "    V-го семестра \n"
            "    факультета ЭИС \n"
            "    группы ПО-4(1) \n"
            "    Галанин П. И. \n"
            "GitHub: \n"
            "    Pavel-Innokentevich-Galanin \n"
            ;
    QMessageBox::about(this, "О программе", str);
}

void TextEditor::gpi_loadFile(const QString &fileName)
{
    if (fileName.isEmpty())
    {
        gpi_setFileName(QString());
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Ошибка", "Файл не открылся");
        gpi_setFileName(QString());
        return;
    }

    QTextStream readFile(&file);
    QString text = readFile.readAll();
    ui->textEdit->setText(text);
    file.close();
    gpi_setFileName(fileName);
    setWindowModified(false);
}

void TextEditor::gpi_setFileName(const QString &name)
{
    this->m_filename = name;
    setWindowTitle(
                QString("%1[*] - %2")
                    .arg(m_filename.isNull()? "untitled":QFileInfo(m_filename).fileName())
                    .arg(QApplication::applicationName())

                );
}

void TextEditor::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open document",
                                                    QDir::currentPath(),
                                                    "Text document (*.txt)");
    if (fileName.isNull())
    {
        return;
    }

    if (fileName.isNull() && !isWindowModified())
    {
        gpi_loadFile(fileName);
        return;
    }

    TextEditor *p = new TextEditor(fileName, this);
    p->show();
}

bool TextEditor::gpi_saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(
                this,
                "Save document",
                this->m_filename.isNull()?QDir::currentPath():m_filename,
                "Text documents (*.txt)"
                );
    if (fileName.isNull())
    {
        return false;
    }

    gpi_setFileName(fileName);
    return gpi_saveFile();
}

bool TextEditor::gpi_saveFile()
{
    if(this->m_filename.isNull())
    {
        return gpi_saveFileAs();
    }

    QFile file(this->m_filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text ))
    {
        QMessageBox::warning(
                    this,
                    "Ошибка",
                    "Файл не найден"
                    );
        gpi_setFileName(QString());
        return false;
    }

    QTextStream fileRead(&file);
    fileRead << ui->textEdit->toPlainText();
    file.close();
    setWindowModified(false);
    return true;
}
