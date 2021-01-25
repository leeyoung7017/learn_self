1mm约等于40mil

1mil约等于0.025mm

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

W快捷键——wire

G快捷键——GND

F快捷键——VCC

X快捷键——电气引脚不连接

搜索元件所在库中：search for part

ALT快捷键——电气连接切断

R快捷键——翻转元器件

H快捷键——水平镜像

V快捷键——垂直镜像

### 同一页面间的非wire连接

N快捷键——wire间的关联电气连接

### 不同页面间的电气连接

OFFPAGELEFT		OFFPAGERIGHT

进行电气连接，名称相同就OK，方向不同no matter

### 总线连接方式

B快捷键——bus总线，如果任意角度要加上shift

E快捷键——bus entry，连接bus总线之后再连接其他引脚

F4快捷键快速连接，按照规律方式

N快捷键——总线命名   name[0:31]

<img src='https://i.loli.net/2021/01/16/lfxrg2LJM4GKUWh.png' title='quicker_8f84c123-cf7d-4a37-a6cb-3c9d83aded0c.png' />

### BROWER命令中进行查看

dsn文件、page文件——edit——brower——按类弹出

parts——元器件的详细信息

nets——网络连接，电源的详细信息

Off-pageconnectors——不同页面间的电气连接

### FIND命令中进行查找

dsn文件、page文件——edit——find

### 批量替换

design cache——选择元件——右击——replace cache——preserve(保存属性)/replace(替换属性)

可以替换修改前后不同属性的同一元器件——update cache

可以替换不同封装的同一元器件——replace cache ——replace

### 电源的赋值

VCC3V3——表明电源3.3V		VCC5V——表明电源5V

### 元器件封装修改

PCB Footprint添加在原理图中

批量修改：批量选中——edit——property///////page——右击——edit project property

### 元器件名称标号

dsn文件、page文件——Tool——annotate

physical packaging 最后一个大括号的内容要改为heterogeneous创建library后的添加属性后的属性名称

### 电气检查

dsn文件——TOOL——design rules check

### 生成网表

dsn文件——tool——create netlist

### 生成元件清单列表

方法一：

dsn文件						![quicker_a7dcfac5-3542-4951-8424-2476a76fa829.png](https://i.loli.net/2021/01/17/vyY7VwsZgceqtMm.png)

![quicker_65a54908-cf10-41be-ab4c-993680c159d8.png](https://i.loli.net/2021/01/17/RfYsjNGoLAVpx35.png)

方法二：

![quicker_dfe5f41c-72e6-498c-89ca-3697d476c332.png](https://i.loli.net/2021/01/17/4fq9zXetlWrsKIk.png)

# PCB绘制

PCB Editor——Allegro PCB Editor XL(可以file—change editor)

view——customize toolbar——菜单配置

shift+鼠标——视图

## class与subclass

options中可以查看class与class下的subclass；display——color visibility下

board geometry——dimension——尺寸

​							 ——Outline——外边框

​							 ——Assembly_Notes——要点信息

​							 ——place_Grid——自动布局有关

​							 ——Rooms——与自动布局有关

​							——Silkscreen——私印信息

stack-up——soldermask——组焊层

​				——pastemask——加焊层

操作前提：需要确定好class—subclass，在哪里画。

## PCB封装

pad designer软件进行封装

type:through(通孔)，blind/buried(盲孔、埋孔)，single(贴片)

internal layers：fixed，optional

units：单位

Multiple drill：孔

drill、slothole：孔和缝隙

layers：封装包含的层，通常也要配置**组焊层—与正常焊盘大0.2mm**与**加焊层—与正常尺寸相同**—regular Pad设置尺寸	***圆形焊盘半径大0.1mm***

### 简单配置

打开进行封装 package symbol

setup——design parameter——design——left x  lower y  都是相对于原点的坐标

setup——grid——改变栅格

### 绘图过程：package_geometry:arrow_right:class

放置引脚:arrow_right:图形边框:arrow_right:参考编号:arrow_right:加栅格(防止多个封装存在重叠)​

layout——pin——option——connect——padstack：引脚的放置

图形边框：assembly_top——add——line   起始坐标【x x0 y0】移动【ix length】【iy length】

​					丝印层元件外形：silkscreen_top层——add line————器件的外轮廓

add ——rectangle——place_bound_top层————查看是否有重叠

参考编号：layout——label——refdes——assembly_top和silkscreen_top层



### 特殊形状的引脚

PCB editer:arrow_right:shape_symble:arrow_right:获取尺寸:arrow_right:用规则图形拼凑（shape中的形状）:arrow_right:shape_merge shapes（融合重叠区域）:arrow_right:create symble:arrow_right:setup——user preference——paths——padpath psmpath设置路径

pad designer——layers——shape







<img src="https://i.loli.net/2021/01/19/JBz9TODg3SsaNGe.png" alt="quicker_081ffd21-042b-4efa-9b81-6764e1551968.png" style="zoom:200%;" />

<img src="https://i.loli.net/2021/01/24/DndKIgJ4wqOyU5M.png" alt="20151013182022818.png"  />

画元器件的PCB的步骤

新建	0

| class            | subclass        | function                             |
| ---------------- | --------------- | ------------------------------------ |
| Package Geometry | Assembly _Top   | LayOut---Pin，Add---Line             |
| Package Geometry | Silkscreen_Top  | Add---Line,同时标注PIN的起始位置line |
| Package Geometry | Place_Bound_Top | Add---Rectangle                      |
| Ref_Des          | Assemably_Top   | Add---Text                           |
| Ref_Des          | Silkscreen_Top  | Add---Text                           |

```
注意:
	1. 对于特殊形状的引脚需要自己画，然后再Pad Designer；而非特殊的引脚一般直接在Pad Designer中产生；
	2. 装配层的边框一般为除引脚外的部分边框，而丝印层的边框一般为该元器件的最大尺寸所占空间；
	3.
```



# 通孔类元件的绘制

reset6*6	引脚宽度0.7mm    钻孔的大小比管脚大10~12mil  =   1mm直径的钻孔   

***负片格式需要花焊盘***

**花焊盘**，梅花焊盘+GND、十字花焊盘-减慢散热，方便焊接、泪滴焊盘-固定性好

尺寸的选取1.5 1.8 0.7 内径=钻孔+6~8mil/20mil   外径=内径+6~8mil/12mil

![quicker_d231089d-4bbf-48ac-88b0-a57a908a9c68.png](https://i.loli.net/2021/01/23/KzJ2rjYHn7Eoed9.png)



| 正规焊盘 Regular pad | Pin1一般所有层为外方内圆，其余的一般为圆环性  |
| -------------------- | --------------------------------------------- |
| 热风焊盘 Thermal pad | 一般为flash焊盘；而在外层放置时同正规焊盘一致 |
| 隔离盘 Anti pad      | 一般比正规焊盘大0.1mm                         |

外层(begin layer与end layer)：填写一致

内层(default internal)：内层为圆环形焊盘

组焊层的top与bottom都要填写一致，大0.1mm

加焊层的top与bottom都要填写一致



按键通孔的pcb配置：阴片与阳片

1. flash焊盘

2. 通常需要与电源层、地层的连接

添加flash图形(add---flash):arrow_right:create symbol

Pad_desinger:arrow_right:Drill:arrow_right:plating(是否上锡):arrow_right:drill/slot symbol​

直插型通孔第一个引脚一般为外方内圆





# 非电气属性引脚的元器件封装

无电气属性的通孔的焊盘只在Top_layer与end_layer上进行焊盘的设置

画引脚，option选择Mechanical

# LP Wizard的操作方法

Calculate——SMD Calculate——查找封装，对应的芯片

查看Land_Top层，左侧点击Land Pattern按钮显示Pin焊盘尺寸

# 各种封装模型

SOIC-----两边都是引脚

PQFP----四周都是引脚

PCB内层板----负片格式----划线的地方没有铜皮，没划线的地方反而有铜皮————常常需要flash焊盘级花焊盘

​					----正片格式----一般不需要flash焊盘







Soldermask_Top	阻焊层	就是我们常说的绿油层，是电路板的非布线层	在阻焊层上预留的焊盘大小，要比实际焊盘大一些，奇差之一般为10~12mil

Pastemask_Top	锡膏防护层(加焊层)	该层用来制作钢膜

regular pad的尺寸和paste mask的尺寸相等，sold mask的尺寸要比regular pad的尺寸大0.1mm

自定义焊盘需要先做shape symbol （一个是regular 另一个是sold mask），然后在做pad

通孔类焊盘，孔径做成比实际尺寸大12mil，内电层的flash内径比孔径大8mil。anti pad要比regular pad大0.1mm

没有电气特性的钻孔，制作焊盘时选择Non-plated，而且只在begin layer和end layer





# 创建电路板

***非自动即手工***

板框：board geometry——outline   确定电路板的形状		

​		倒角：chamfer——45度倒角————放置电路板的四个直角太过锋利划伤自己

​					fillet——圆弧倒角

![image-20210125205004647](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20210125205004647.png)