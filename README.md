# 基于Qt的多客户端TCP通信设计

#### 介绍
    该项目基于Qt的多客户端TCP通信系统，采用了TCP传输控制协议进行客户端与服务端安全通信。服务端采用了QThread多线程对客户端高并发响应，连接了sqlite数据库对通信记录，及ip+port进行存储。当然，也采用了QT中的Viewtable控件，将数据表中的数据整体展示出来。
    需要注意的是: 1. 该项目分为客户端和服务端，分别对应文件TCPClient、TCPServer项目文件，为了展示多客户端同时访问，服务端的并发处理设计，可以同时启动多个客户端(即运行多个TCPClient项目文件)  2.为了能在ARM开发板上展示效果，作者将TCPClient、TCPServer项目文件融合成了一个TCPServer_项目文件，单次运行可同时出现客户端和服务端
    

#### 软件架构
软件架构说明


#### 安装教程

1.  xxxx
2.  xxxx
3.  xxxx

#### 使用说明

1.  xxxx
2.  xxxx
3.  xxxx

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)
