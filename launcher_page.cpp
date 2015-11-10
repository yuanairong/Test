#include "launcher_page.h"
#include "ui_launcher_page.h"
#include "global.h"
#include <QWidget>
#include <QScrollArea>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QDir>
#include <QFileDialog>
#include <QDebug>


Launcher_page::Launcher_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Launcher_page)
{
    ui->setupUi(this);

    initWidget();
    disableWidget();
}

Launcher_page::~Launcher_page()
{
    delete ui;
}

void Launcher_page::initWidget()
{
    lbl_wallpaper = new QLabel("WallpaperPath:");
    le_wallpaper = new QLineEdit();
    le_wallpaper->setFixedWidth(500);
    btn_select_wallper = new QPushButton("...");
    lbl_icon_site = new QLabel("Icon Site");
    btn_icon_site = new QPushButton("打开配置文件");
    btn_icon_site->setFixedWidth(100);

    hSpacer = new QSpacerItem(600, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    vSpacer = new QSpacerItem(20, 800, QSizePolicy::Expanding, QSizePolicy::Expanding);

    scroll = new QScrollArea();
    scroll->setWidgetResizable(true);
    scrollWidget = new QWidget(scroll);
    scroll->setWidget(scrollWidget);
    gridLayout = new QGridLayout(scrollWidget);
    gridLayout->addWidget(lbl_wallpaper, 0, 0);
    gridLayout->addWidget(le_wallpaper, 0, 1);
    gridLayout->addWidget(btn_select_wallper, 0, 2);
    gridLayout->addItem(hSpacer, 0, 3);
    gridLayout->addWidget(lbl_icon_site, 1, 0);
    gridLayout->addWidget(btn_icon_site, 1, 1);
    gridLayout->addItem(vSpacer, 2, 0);

    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(scroll);


}

void Launcher_page::disableWidget()
{
    QList<QObject *> list = scrollWidget->children();
    QWidget *w;
    for(int i = 1; i < list.count(); i++)
    {
        w = qobject_cast<QWidget *>(list.at(i));
        w->setDisabled(true);
    }
}

void Launcher_page::enableWidget()
{
    QList<QObject *> list = scrollWidget->children();
    QWidget *w;
    for(int i = 1; i < list.count(); i++)
    {
        w = qobject_cast<QWidget *>(list.at(i));
        w->setEnabled(true);
    }
}

void Launcher_page::cpWallpaper(QString extWallpaperPath)
{
    QString wallpaperPath = Global::srcPath + "/packages/apps/Launcher3/res/drawable-sw600dp-nodpi/";
    QDir *dir = new QDir(extWallpaperPath);
    QStringList fileList = dir->entryList();
    for(int i = 2; i < fileList.length(); i++)
    {
        QFile::copy(extWallpaperPath + "/" + fileList[i], wallpaperPath + fileList[i]);
        // qDebug() << extWallpaperPath + "/" + fileList[i] << endl << wallpaperPath + fileList[i];
    }

}

void Launcher_page::btn_wallpaper_choose()
{
    QFileDialog *fileDlg = new QFileDialog();
    QString wallpaperPath = fileDlg->getExistingDirectory(this);
    //ui->le_wallpaperPath->setText(wallpaperPath);
   // cpWallpaper(wallpaperPath);
}


