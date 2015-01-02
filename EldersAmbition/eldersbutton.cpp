#include "eldersbutton.h"

EldersButton::EldersButton(QWidget *parent) :
    QPushButton(parent)
{
    //保存图片成员初始化
    buttonPicture = new QPixmap(":/images/assets/Images/buttonNormal.png");
    pressPicture = new QPixmap(":/images/assets/Images/buttonPressed.png");
    this->setIcon(QIcon(*buttonPicture));

    //releasePicture = new QPixmap();

    //enterPicture = new QPixmap();
    //leavePicture = new QPixmap();

    //关闭按钮的默认显示
    this ->setFlat(true);
    this->setFocusPolicy(Qt::NoFocus);

    //初始化flag
    flag=false;

    this -> setIconSize(QSize(56, 26));
    this -> setGeometry(10, 10, 56, 26);
}

void EldersButton::setButtonPicture(QPixmap pic)
{
        *buttonPicture = pic;
        this->setIcon(QIcon(*buttonPicture));
}

void EldersButton::setPressPicture(QPixmap pic)
{
        *pressPicture = pic;
}

void EldersButton::set_X_Y_width_height(int x, int y, int width, int height)
{
        this -> setIconSize(QSize(width, height));
        this -> setGeometry(x, y, width, height);
}

void EldersButton::mousePressEvent (QMouseEvent *event)
{
        this -> setIcon(QIcon(*pressPicture));
}

void EldersButton::mouseReleaseEvent (QMouseEvent *event)
{
        this -> setIcon(QIcon(*buttonPicture));
        emit clicked();
}
