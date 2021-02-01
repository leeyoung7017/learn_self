# 项目创建步骤

## 1.原理图的绘制_Design Entry CIS

<img src="https://i.loli.net/2021/01/25/WAB4rc2SnLwCFGM.png" alt="cadence原理图绘制.png" style="zoom:60%;" />

### 	1.1.library

* 新建library	:star:新建路径不要有中文

* 新建part	是否选择Homogeneous、heterogeneous

````c
Homogeneous：表示每个package下的多个part属于同源
heterogeneous：表示每个package下的多个part不属于同源
    ctrl+N：表示在homogeneous、heterogeneous情况下，走向下一个
````

* library的技巧
  * 取消栅格点：option_preference_grid display
  * 批量引脚：place_pin array   :star:注意type
  
  ### 1.2.project
  
* #### 新建project

​	:star:新建路径不要有中文

* #### 新建page

* #### project的技巧

  * | 快捷键 |                    指令                    |
    | :----: | :----------------------------------------: |
    |   W    |                    wire                    |
    |   N    |                wire名称连接                |
    |   B    |       bus总线    总线命名 name[0:30]       |
    |   J    |                junction节点                |
    |   X    |            place no connection             |
    |   P    |          place part    显示元器件          |
    |   E    |              place bus entry               |
    |   F    | VCC_power，VCC5V(5V电压)、VCC3V3(3.3V电压) |
    |   G    |                    GND                     |

  * | 快捷键           | 指令                     |
    | ---------------- | ------------------------ |
    | page间的电气连接 | place off-page connector |
    | ALT              | 电气切断                 |
    | V                | 垂直镜像                 |
    | H                | 水平镜像                 |
    | R                | 翻转元器件               |

  * bus总线的使用：

    * 地址总线，数据总线等批量线的连接
    * 总线与多引脚间的连接必须使用	place bus entry（快捷键E）
    * F4快捷键的使用，按照规律重复

  * brower命令    find命令

  * 批量替换

  * 元器件封装修改

* #### 电气检查

<img src="https://i.loli.net/2021/01/26/GRaiwVCzyLdFNSc.png" alt="电气检查.png" style="zoom:60%;" />

* #### 生成网表，元件清单列表

  <img src="https://i.loli.net/2021/01/26/4NgEJa9xAeXKqbU.png" alt="网表.png" style="zoom:60%;" /><img src="https://i.loli.net/2021/01/26/D1PblZNeryUM7mA.png" alt="元器件清单.png" style="zoom:60%;" />

## 2.元器件封装_Pad designer___PCB Editor

<img src="https://i.loli.net/2021/01/19/JBz9TODg3SsaNGe.png" alt="quicker_081ffd21-042b-4efa-9b81-6764e1551968.png" style="zoom: 55%;" />

<img src="https://i.loli.net/2021/01/24/DndKIgJ4wqOyU5M.png" alt="20151013182022818.png" style="zoom:55%;" />

### 	2.1.新建package symbol——非自动(non wizrard)

| class            | subclass        | function                             |
| ---------------- | --------------- | ------------------------------------ |
| Package Geometry | Assembly _Top   | LayOut---Pin，Add---Line             |
| Package Geometry | Silkscreen_Top  | Add---Line,同时标注PIN的起始位置line |
| Package Geometry | Place_Bound_Top | Add---Rectangle                      |
| Ref_Des          | Assemably_Top   | Add---Text                           |
| Ref_Des          | Silkscreen_Top  | Add---Text                           |

* :star:注意：特殊类引脚需要在PCB_Editor的shape symbol建立
* :star:注意：摆放引脚时options内部的各个选项的含义
* :star:注意：多引脚的情况下需要标注那个角是初始角，需要用一个点来标注初始角的边

  ### 2.2.新建 shape symbol

* 使用各种图形可以进行拼凑形成

* 完毕之后使用Shape_merge shapes将规则图形进行合并
* 进行create symbol
* :star:如果在Pad_Desinger下找不到该焊盘，需要在PCB_Editor下查找user preference_paths_padpath/psmpath设置路径

  ### 2.3.新建flash symbol

#### 创建flash symbol，一般是为了创建花焊盘，创建通孔而设计的

**花焊盘**，是在PCB板的内层板中使用，如果内层板使用负片格式，则会使用花焊盘，而如果使用的是正片格式，则就不需要花焊盘。其中花焊盘包括梅花焊盘、十字花焊盘、泪滴焊盘等等，各种花焊盘有着各种的独特作用和用途。

#### 花焊盘尺寸的设计

|    ID     | Inner diameter 内径 |
| :-------: | :-----------------: |
|    OD     | Outer diameter 外径 |
| Anti-pad  |       阻焊盘        |
|   Spoke   |        开口         |
| 焊盘直径d |      外形直径       |
| 焊盘孔径h |      钻孔直径       |

**各尺寸计算：**已知元件引脚的直径D

1. 计算PCB焊盘的孔径h

|    D<40mil    | h=D+12mil |
| :-----------: | :-------: |
| 40mil<D<80mil | h=D+16mil |
|    D>80mil    | h=D+20mil |

2. 计算焊盘直径d：因为焊盘黏锡部分的宽度要保证至少≥10mil,所以焊盘直径

$$
d=h + 10mil
$$

3. 计算花焊盆的内径ID

$$
ID=\it钻孔直径h+20mil
$$

4. 计算花焊盘的外径OD

$$
OD= \it焊盘直径d+20mil
$$

5. 计算开口 Spoke的宽度

$$
Spoke width=(OD-ID)/2+ 10mil
$$

6. 计算阻焊盘直径Anti_pad

$$
=OD
$$

#### 需要进行create symbol

### 	2.4.创建引脚Pad_Editor 

regular pad的尺寸一般比引脚尺寸内外侧补偿大约0.4~0.6mm

其他层或者anti pad的尺寸一般比规则焊盘补偿0.1~0.5mm

#### 非通孔类

* 设置为毫米格式
* 选择 single layer mode
* 为begin layer、pastemask_top、soldmask_top的焊盘进行配置
* :star:注意：在配置焊盘尺寸时，需要将soldmask_top的尺寸扩大0.1mm
* :star:注意：如果为特殊引脚需要在shape选项出选择shape，然后在flash下选择进行所需的形状引脚
* :star:如果在Pad_Desinger下找不到该焊盘，需要在PCB_Editor下查找user preference_paths_padpath/psmpath设置路径

#### 通孔类

* 在PCB_editor下创建了花焊盘之后打开Pad——editor
* 设置为毫米格式
* Drill/Slot hole 进行配置Hole type(孔的形式)、plating(挂不挂锡)、Drill diameter(孔径大小)
* Drill/Slot symbol进行配置figure(一般为Hexagon X)，character(每次通孔的内容不一致)、width/height(一般孔径要小)
* 不要选择single layer mode
* regular pad是设置尺寸与thermal relief尺寸一致，thermal relief为flash，而anti pad的尺寸要大0.1mm
* :star:注意：一个元器件上规则的多个引脚为通孔，需要将Pin 1的焊盘设置为方形，孔为circle
* :star:注意：上面的所有layer都需要标注(内层、外层、阻焊层，加焊层)，其中soldmask的两个层的尺寸大0.1mm

#### 固定孔

* 与通孔类的配置一致，要求通孔尺寸要比焊盘大，所以按照通孔的要求做完之后，主要改正内外层的焊盘尺寸
* 固定孔所在pcb板的四角，同时固定孔属于不挂锡的模式，即Non-Plated

## 3.电路板的绘制_PCB Editor

### 	3.1.电路板绘制准备

1. 创建board，可以是board(wizard)

2. 在Board_Geometry下的outline下绘制板型，即板子的形状

3. 为了不划伤手，需要进行倒角

   * manufacture_drafting_chamfer(45度倒角)/fillet(弧形倒角)

4. 之后就需要设置布线区域与放置区域

   * Setup_Areas_package keepin、route keepin
   * 一般布线区域与放置区域尺寸同等
   * 布线区域与放置区域一般比板型小200mil

5. 之后设置板层，Setup_cross section配置电源层与地层

   * | 选项     |                                                      |
     | -------- | ---------------------------------------------------- |
     | type     | conductor(导电层)、dielectric(介质层)、plane(内电层) |
     | material | copper(铜)、FR-4                                     |
     
   * | 选项               |                                              |
     | ------------------ | -------------------------------------------- |
     | Etch subclass name | top、bottom、内电层：GND层、电源层           |
     | negative artwork   | 是否选择为**负片格式**，内电层往往为负片格式 |

6. GND与POWER层的铺铜结构
   
   * Z_copy命令的使用，option中选上create dynamic shape，选择布线区域内部
7. 放置固定孔
   
   * 固定孔的位置
8. 导入网表，设置栅格点
   
   * File_import_logic..
   
   ### 3.2.元器件的放置

| 放置方式         | 方法                                                         |
| ---------------- | ------------------------------------------------------------ |
| 手动放置         | place_manually                                               |
| 交互放置         | 原理图中设置option_preference_miscellaneous_勾选enable intertool communication |
|                  | 在PCB中打开manually，在原理图中右击元器件后shift+s           |
| 按照自写属性放置 | 原理图中为批量的元器件添加同一属性与value值                  |
|                  | 重新生成网表(setup_edit需要更改)_选中下列\_点击user property |
|                  | 在PCB中重新导入网表，选中user property                       |
|                  | quickplace_place by property/value进行选择；选择摆放的位置   |
| **按照room放置** | 更改元器件的属性edit_property                                |
| 这种方法常用在   | find_选择comp(or pin)，选择放入一个room的元器件              |
| 标注功能模块化   | 弹出的对话框中找到room，添加value值                          |
|                  | setup_outlines_room outlines——画出作为room为value的区域，修改也是这样操作 |
|                  | quickplace_选择place by room                                 |
|                  |                                                              |
|                  |                                                              |

| 元器件摆放方式 | 未放置      | 已放置                |
| -------------- | ----------- | --------------------- |
| 镜像摆放       | mirror      | edit_mirror           |
| 翻转摆放       | 右击_rotate | edit_move+右击_rotate |

### 	3.3.放置与布线规则