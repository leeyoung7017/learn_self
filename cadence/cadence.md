# library的创建

olb文件创建 - newpart

引脚类型的选择和名称

放置引脚数组：place - Pin Array

## 简单元器件

（一个元器件画一个图）

## 复杂元器件

（一个元器件画多个图）

multiple-part——homogeneous（图像相同关联）heterogeneous（图形功能无关）

# project的创建

## 添加OLB原件库

place - part（P快捷键）-add library

## [常用库](C:\Cadence\SPB_16.6\tools\capture\library)

DISCRETE——电容(cap np)、电阻、电感、二极管

VCC  GND 在选择条bar上存在

## 画原理图

N快捷键——wire间的关联

W快捷键——wire

G快捷键——GND

F快捷键——VCC

X快捷键——电气引脚不连接

搜索元件所在库中：search for part

## 不同页面间的电气连接

OFFPAGELEFT

OFFPAGERIGHT

进行电气连接，名称相同就OK，方向不同no matter

## 总线连接方式

B快捷键——bus总线，如果任意角度要加上shift

E快捷键——bus entry，连接bus总线之后再连接其他引脚

F4快捷键快速连接，按照规律方式

N快捷键——总线命名   name[0:31]

<img src='https://i.loli.net/2021/01/16/lfxrg2LJM4GKUWh.png' title='quicker_8f84c123-cf7d-4a37-a6cb-3c9d83aded0c.png' />

## BROWER命令中进行查找

dsn文件——edit——brower——按类弹出