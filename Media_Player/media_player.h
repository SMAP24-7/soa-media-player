#ifndef MEDIA_PLAYER_H
#define MEDIA_PLAYER_H

#include <QMainWindow>

#include <QVideoWidget>
#include <QCameraViewfinder>
#include <QCamera>
#include <QMediaPlayer>
#include <QMessageBox>
#include <QFileDialog>


namespace Ui {
class QVideoWidget;
class Media_Player;
}

class Media_Player : public QMainWindow
{
    Q_OBJECT

public:
    explicit Media_Player(QWidget *parent = 0);
    ~Media_Player();

private slots:
    void on_Webcam_clicked();

    void on_Play_clicked();

    void on_Stop_clicked();

    void on_Rewind_clicked();

    void on_Forwad_clicked();
private:
    Ui::Media_Player *ui;

    QCamera* camera = new QCamera;
    QVideoWidget* VideoWdiget = new QVideoWidget;
    QMediaPlayer* player = new QMediaPlayer;
    QString fileName;
    qreal v_reproduccion;
    QMessageBox Qmessageerror;



    void Velocidad_Reproduccion();
    void Set_Name_Speed_Button();
};

#endif // MEDIA_PLAYER_H
