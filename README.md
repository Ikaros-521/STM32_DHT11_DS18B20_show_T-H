# 前言

参考资料：

&nbsp;&nbsp;&nbsp;&nbsp;YL-47 DHT11 使用说明--.pdf

&nbsp;&nbsp;&nbsp;&nbsp;DHT11说明书最新版--.pdf

&nbsp;&nbsp;&nbsp;&nbsp;DHT11模块--.pdf

&nbsp;&nbsp;&nbsp;&nbsp;[DHT11模块使用说明书](https://wenku.baidu.com/view/19defe09524de518964b7df5.html)

&nbsp;&nbsp;&nbsp;&nbsp;DS18B20.pdf

&nbsp;&nbsp;&nbsp;&nbsp;[ds18b20中文资料详解](http://www.elecfans.com/yuanqijian/sensor/20171106575662.html)

源码参考：野火dht11温湿度传感器测试实验，正点原子TFTLCD显示实验 18B20数字温度传感器实验

开发板：正点原子 STM32F103 精英版

语言：C语言

开发环境：Keil5

**开发板**使用了 LED  TFTLCD USART DHT11模块 DS18B20模块 

## 代码下载：

[码云](https://gitee.com/ikaros-521/STM32_DHT11_DS18B20_show_T-H) [GitHub](https://github.com/Ikaros-521/STM32_DHT11_DS18B20_show_T-H)

## 功能介绍：

&nbsp;&nbsp;&nbsp;&nbsp;LED0约2秒一闪，表示程序运行中。

&nbsp;&nbsp;&nbsp;&nbsp;LCD和串口显示实时的温湿度，2秒一循环。

&nbsp;&nbsp;&nbsp;&nbsp;%RH 相对湿度，  CEL 摄氏度（ps：不接入DS18B20的话会循环等待）

# 接线

## DS18B20

VCC   -》 3.3V

DQ     -》 PG11

GND  -》 GND

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425141048168.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

## DHT11

VCC   -》 3.3V

DATA -》 PB10

GND  -》 GND

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425141316159.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

# 效果图

## 普通环境

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425142439796.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425141720248.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

## 哈热气

我这哈了3下

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425141812267.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

然后持续手扇风

![在这里插入图片描述](https://img-blog.csdnimg.cn/202104251418503.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

ok，温湿度降下来了。

## 搓手捂热

手有汗，湿度也上来了

（下图是旧的，仅供参考）

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425101542440.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425142145512.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

最后本来应该整个打火机的，可惜没有。夹咯吱窝下（仅DHT11 旧图）

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425102504156.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

最后来个鼻息

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425142526110.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

# 参考用图

## DHT11

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425103221944.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425103256452.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425103350397.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425103509225.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

## DS18B20

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425143157990.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425143212203.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/2021042514344976.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210425143458770.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0lrYXJvc181MjE=,size_16,color_FFFFFF,t_70)
