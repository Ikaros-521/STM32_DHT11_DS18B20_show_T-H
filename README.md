# 前言

参考资料：

&nbsp;&nbsp;&nbsp;&nbsp;YL-47 DHT11 使用说明--.pdf

&nbsp;&nbsp;&nbsp;&nbsp;DHT11说明书最新版--.pdf

&nbsp;&nbsp;&nbsp;&nbsp;DHT11模块--.pdf

&nbsp;&nbsp;&nbsp;&nbsp;[DHT11模块使用说明书](https://wenku.baidu.com/view/19defe09524de518964b7df5.html)

源码参考：野火dht11温湿度传感器测试实验，正点原子TFTLCD显示实验

开发板：正点原子 STM32F103 精英版

语言：C语言

开发环境：Keil5

**开发板**使用了 LED  TFTLCD USART DHT11模块

## 代码下载：

[码云](https://gitee.com/ikaros-521/STM32_DHT11_show_T-H) [GitHub](https://github.com/Ikaros-521/STM32_DHT11_show_T-H)

## 功能介绍：

&nbsp;&nbsp;&nbsp;&nbsp;LED0约2秒一闪，表示程序运行中。

&nbsp;&nbsp;&nbsp;&nbsp;LCD和串口显示实时的温湿度，2秒一循环。

&nbsp;&nbsp;&nbsp;&nbsp;%RH 相对湿度，  CEL 摄氏度

# 接线

VCC   -》 3.3V

DATA -》 PB10

GND  -》 GND

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425100606555.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

# 效果图

## 普通环境

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425100824457.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425100750643.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

## 哈热气

我这哈了3下

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425101019683.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425100923207.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

然后持续手扇风

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425101106680.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

ok，温湿度回到室温环境。

## 搓手捂热

手有汗，湿度也上来了

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425101542440.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425101624326.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

最后本来应该整个打火机的，可惜没有。夹咯吱窝下

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425102504156.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

最后来个鼻息

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425102625324.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

# 参考用图

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425103221944.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425103256452.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425103350397.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425103509225.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

