#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <graphics.h>

using namespace std;

class Brick
{

private:
    int x;
    int y;//ͼƬ����
    int width=100;//��
    int height=100;//��
    int status = 0;//0-11  12��ͼƬ
    void initBoard();//��ʼ������
    void draw();//��ʼ����
public:
    // �洢ͼƬ
    static IMAGE image[12];

    //Ĭ�Ϲ���
    Brick() : Brick(0, 0, 100, 100) {
    }
    // 
    Brick(int x, int y):Brick(x,y,100,100){
        
    }
    Brick(int x, int y,int w,int h) : x(x), y(y),width(w),height(h) {
        loadImages();
    }

    // ����
    ~Brick() {}
  
    int getX();
    int getY();
    int getWidth();
    int getHeight();

    // Static method to load images
    void loadImages();
    //ͼƬ״̬ �ڼ���ͼƬ
    int statusSet(int s);
    //�����
    void mouseEvent();

    void game();
};

// Initialize
IMAGE Brick::image[12];