#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include <QDockWidget>
#include <QListWidget>
#include <QStatusBar>
#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QCloseEvent>
#include <QTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QStatusBar>
#include <QLabel>
#include <QTextStream>
#include <memory>
#include <QDebug>

#include "lib\ui\dwellercanvas.h"
#include "lib\tool\drawdoortool.h"
#include "lib\tool\drawfloortool.h"
#include "lib\tool\drawwalltool.h"
#include "lib\tool\drawdevicetool.h"
#include "lib\tool\drawwindowtool.h"
#include "lib\tool\selectiontool.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow();

protected:
    //void closeEvent(QCloseEvent *event);

private slots:
    //Action triggerd
    void on_actionNewFile();
    void on_actionOpenFile();
    void on_actionSaveFile();
    void on_actionSaveAs();
    void on_actionExit();

    void on_actionCut();
    void on_actionCopy();
    void on_actionPaste();
    void on_actionDelete();
    void on_actionSimulate();
    void on_actionShowSetting();
    void on_actionSelect();

    void on_actionAbout();
    void on_actionDrawWall();
    void on_actionDrawWindow();
    void on_actionDrawDoor();
    void on_actionDrawFloor();
    void on_actionDrawDevice();

private:
    //Layout
    void initScene();
    void createActions();
    void createMenuBar();
    void createSettingBar();
    void createToolBar();
    void createStatusBar();

    //Menu

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *windowMenu;
    QMenu *aboutMenu;

    QToolBar *fileToolBar;
    QToolBar *paintToolBar;

    QLabel *statusBarMessage;

    QDockWidget *settingDock;
    QListWidget *settingList;

    DwellerCanvas *canvas;


    //Actions
    QAction *newFileAction;
    QAction *openFileAction;
    QAction *saveFileAction;
    QAction *saveAsFileAction;
    QAction *exitAction;

    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *deleteAction;

    QAction *simulateAction;
    QAction *showSettingAction;

    QAction *aboutAction;

    QAction *selectAction;
    QAction *drawWallAction;
    QAction *drawWindowAction;
    QAction *drawDoorAction;
    QAction *drawFloorAction;
    QAction *drawDeviceAction;

    //tools
    std::unique_ptr<DrawDeviceTool> m_DeviceTool;
    std::unique_ptr<DrawDoorTool> m_DoorTool;
    std::unique_ptr<DrawFloorTool> m_FloorTool;
    std::unique_ptr<DrawWallTool> m_WallTool;
    std::unique_ptr<DrawWindowTool> m_WindowTool;
    std::unique_ptr<SelectionTool> m_SelectionTool;


};

#endif // MAINWINDOW_H
