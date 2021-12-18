#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QMessageBox> // QMessageBox::warning(...);
#include <QCloseEvent> // QCloseEvent* e
#include <QIcon> //QIcon()
#include <QFontDialog>
#include <QSettings>
#include <QFile> //QFile _();
#include <QFileDialog> // QFileDialog::getOpenFileName
#include <QDir> // QDir::currentPath

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(const QString &fileName = QString(), QWidget *parent = nullptr);
    ~TextEditor();

private slots:
    void on_actionNew_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void gpi_documentModified(); // придуманная функция

    void on_actionSelectFont_triggered();

    void gpi_on_actionAboutQt_triggered();
    void gpi_on_actionCopy_triggered();
    void gpi_on_actionCut_triggered();
    void gpi_on_actionPaste_triggered();
    void gpi_on_actionUndo_triggered();
    void gpi_on_actionRedo_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_triggered();

    bool gpi_saveFile();
    bool gpi_saveFileAs();

protected:
    void closeEvent(QCloseEvent *e); // перегруженная функция
    void gpi_loadFile(const QString &fileName);
    void gpi_setFileName(const QString &name);

private:
    Ui::TextEditor *ui;
    QString m_filename;
};
#endif // TEXTEDITOR_H
