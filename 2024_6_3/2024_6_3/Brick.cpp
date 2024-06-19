#include "Brick.h"

void Brick::initBoard() {
    //��ʼ������
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
    //ͼƬ״̬ �ڼ���ͼƬ
    int Brick::statusSet(int s) {
        if (s >= 12)
            s %= 12;
        if (s < 0)
            s = 11;
        return s;
    }
    //�����
    void Brick::mouseEvent()
    {
        MOUSEMSG msg = GetMouseMsg();//��ȡ�����Ϣ

        //������
        if (msg.uMsg == WM_LBUTTONDOWN)
        {
            putimage(x * width, y * height, &image[statusSet(++status)]);
        }
        //����Ҽ�
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
            if (GetAsyncKeyState(27))//��esc����
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