#include "Brick.h"

void Brick::initBoard() {
    //初始化界面
    initgraph(width, height);
}
void Brick::draw() {
    putimage(x * width, y * height, &image[0]);
}


    int Brick::getX() {
        return x;
    }
    int Brick::getY() {
        return y;
    }
    int Brick::getWidth() {
        return width;
    }
    int Brick::getHeight() {
        return height;
    }

    // Static method to load images
    void Brick::loadImages() {
        char str[50] = { 0 };
        for (int i = 0; i < 12; i++) {
            snprintf(str, sizeof(str), "./images/%d.jpg", i);
            loadimage(&image[i], str, width, height);
        }
    }
    //图片状态 第几个图片
    int Brick::statusSet(int s) {
        if (s >= 12)
            s %= 12;
        if (s < 0)
            s = 11;
        return s;
    }
    //鼠标点击
    void Brick::mouseEvent()
    {
        MOUSEMSG msg = GetMouseMsg();//获取鼠标信息

        //点击左键
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            putimage(x * width, y * height, &image[statusSet(++status)]);
        }
        //点击右键
        else if (msg.uMsg == WM_RBUTTONDOWN)
        {
            putimage(x * width, y * height, &image[statusSet(--status)]);
        }
    }

    void Brick::game() {
        initBoard();
        draw();
        while (1)
        {
            mouseEvent();
            if (GetAsyncKeyState(27))//按esc结束
            {
                closegraph();
                break;
            }
        }
    }
int main() {
	Brick b;
    b.game();

	return 0;
}