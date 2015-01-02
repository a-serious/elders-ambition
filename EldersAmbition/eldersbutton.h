#ifndef ELDERSBUTTON_H
#define ELDERSBUTTON_H

#include <QPushButton>

class EldersButton : public QPushButton
{
    Q_OBJECT
public:
    explicit EldersButton(QWidget *parent = 0);
    void setButtonPicture(QPixmap pic);
    void setPressPicture(QPixmap pic);
    void set_X_Y_width_height(int x, int y, int width, int height);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    bool flag;
};

#endif // ELDERSBUTTON_H
