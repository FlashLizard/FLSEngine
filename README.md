# FLS_Engine

## 1. 介绍

一个用C++写的极其简陋的游戏引擎。可以看作一个玩具 （

## 2. 功能

- [x] 3D渲染
- [x] 基本架构
- [ ] 物理系统
- [ ] UI系统

## 3. 编译

首先下载库glm(>0.9.9)

然后在项目根目录下运行

```bash
make
```

如果仍然找不到glm库，可在Makefile中指定glm的路径。
成功make后，根目录下会生成libflengine.a静态库文件，在链接其他项目时一同链接即可。

## 4. 示例

可以查看 <https://github.com/FlashLizard/OrangePiLab.git> 中的lab6
这是一个使用本引擎制作的非常简单的Minecraft demo。

## 5. 使用介绍

### 5.1. 基本架构

1. 软渲染器部分

- BaseShader: 渲染程序的基类，定义了渲染程序的接口，包括顶点着色函数，片段着色函数，对VertexBundle的加载函数，附加片段信息的生成函数，光照的设置函数。一般来说不同的VertexBundle要用不同的Shader来加载。以下是继承于该类的渲染程序
    - OneColorShader：单色渲染程序，无光照，单色渲染，对应的VertexBundle类型为OneColorVB
    - LerpColorShader
    - TextureShader
    - TextureLightShader

- ShaderRunner

- 
