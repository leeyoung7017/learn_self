# 项目创建步骤

## 原理图的绘制_Design Entry CIS

![cadence原理图绘制.png](https://i.loli.net/2021/01/25/WAB4rc2SnLwCFGM.png)

### library

* 新建library	:star:新建路径不要有中文

* 新建part	是否选择Homogeneous、heterogeneous

````c
Homogeneous：表示每个package下的多个part属于同源
heterogeneous：表示每个package下的多个part不属于同源
````

* library的技巧
  * 取消栅格点：option_preference_grid display
  * 批量引脚：place_pin array   :star:注意type

### project

* 新建project	:star:新建路径不要有中文

* project的技巧

  * | 快捷键 | 指令                |
    | ------ | ------------------- |
    | W      | wire                |
    | N      | wire名称连接        |
    | B      | bus总线             |
    | J      | junction节点        |
    | G      | GND                 |
    | F      | VCC_power           |
    | X      | place no connection |
    |        |                     |
    |        |                     |

    

## 元器件封装_Pad designer___PCB Editor











## 电路板的绘制_PCB Editor

