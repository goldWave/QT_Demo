本工程为在CMake 环境下，使用 visual studio 开发。
使用Qt LinguistTools 配置 ts 文件，并最终生成 qm 文件的 demo 代码

![Snipaste_2024-11-04_21-39-10](https://github.com/user-attachments/assets/5a870a72-0643-48d2-a2fa-fb04c95312c5)

#工程配置步骤

-  `configuure.cmd` 中修改VS的版本，及Qt路径
-  cmd窗口 运行`configuure.cmd`，会创建build 路径
-  在 build 路径中，双击`vs_qtTrans.sln` 打开项目
-  在 vs 中将 `vs_qtTrans` 修改为启动项
-  运行项目

# 翻译功能使用方法
- cpp 或ui 中添加待翻译字符串
- ts 文件，使用Qt Linguist（预言家） 打开并编辑
- 再次build 运行项目即可
  具体详细流程可参考 [Blog](https://blog.csdn.net/goldWave01/article/details/143469347?fromshare=blogdetail&sharetype=blogdetail&sharerId=143469347&sharerefer=PC&sharesource=goldWave01&sharefrom=from_link)

