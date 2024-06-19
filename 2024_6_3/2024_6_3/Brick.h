#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <graphics.h>

using namespace std;

class Brick
{

private:
    int x;
    int y;//图片坐标
    int width=100;//宽
    int height=100;//高
    int status = 0;//0-11  12个图片
    void initBoard();//初始化棋盘
    void draw();//初始加载
public:
    // 存储图片
    static IMAGE image[12];

    //默认构造
    Brick() : Brick(0, 0, 100, 100) {
    }
    // 
    Brick(int x, int y):Brick(x,y,100,100){
        
    }
    Brick(int x, int y,int w,int h) : x(x), y(y),width(w),height(h) {
        loadImages();
    }

    // 析构
    ~Brick() {}
  
    int getX();
    int getY();
    int getWidth();
    int getHeight();

    // Static method to load images
    void loadImages();
    //图片状态 第几个图片
    int statusSet(int s);
    //鼠标点击
    void mouseEvent();

    void game();
};

// Initialize
IMAGE Brick::image[12];