# 软件工程结对作业：自动生成小学四则运算题目的命令行程序

## 需求分析

### 参数控制模块

程序支持如下参数的给定

- `-n <num>` 控制题目生成个数
- `-r <num>` 控制题目中的数值范围，例如输入10则数值范围为0~9
- `-e <exercisefile>.txt -a <answerfile>.txt` 根据给定的 `exercisefile` 和 `answerfile` 判定题目

需要对参数获取并进行功能选取

### 分数表示类

参考来源：[C++分数类 by 拱大垲-博客园](https://www.cnblogs.com/gongkai/p/10806080.html)



### 树结构

用于存储算式

提供如下操作

### 题目生成模块

### 题目判定模块

### 文件IO模块

将生成的题目列表写入文件 `Exercises.txt`，将对应的答案列表写入文件 `Answers.txt`

读取 `<exercisefile>.txt` 中的题目文件，读取 `<answerfile>.txt` 中的答案文件



文件格式如下

题目文件

```txt
1.题目1
2.题目2
...
```

答案文件

```txt
1.答案1
2.答案2
...
```

### 报错提示模块

参数不合法异常

对参数 `-n <num>` 和 `-r <num>` 需要保证 `<num> > 0`

对参数 `-e` 和 `-a` 需要同时接收并且检查 `<exercisefile>.txt` 和 `<answerfile>.txt` 能否正常读取



# PSP表

| PSP2.1                                  | Personal Software Process Stages        | 预估耗时（分钟） | 实际耗时（分钟） |
| --------------------------------------- | --------------------------------------- | ---------------- | ---------------- |
| Planning                                | 计划                                    |                  |                  |
| · Estimate                              | · 估计这个任务需要多少时间              |                  |                  |
| Development                             | 开发                                    |                  |                  |
| · Analysis                              | · 需求分析 (包括学习新技术)             |                  |                  |
| · Design Spec                           | · 生成设计文档                          |                  |                  |
| · Design Review                         | · 设计复审 (和同事审核设计文档)         |                  |                  |
| · Coding Standard                       | · 代码规范 (为目前的开发制定合适的规范) |                  |                  |
| · Design                                | · 具体设计                              |                  |                  |
| · Coding                                | · 具体编码                              |                  |                  |
| · Code Review                           | · 代码复审                              |                  |                  |
| · Test                                  | · 测试（自我测试，修改代码，提交修改）  |                  |                  |
| Reporting                               | 报告                                    |                  |                  |
| · Test Report                           | · 测试报告                              |                  |                  |
| · Size Measurement                      | · 计算工作量                            |                  |                  |
| · Postmortem & Process Improvement Plan | · 事后总结, 并提出过程改进计划          |                  |                  |
| 合计                                    |                                         |                  |                  |

# Code Standard

借鉴微软和Unity风格

## 命名

每种成员后方即为标准命名（命名样式名称和预览），中括号扩起的部分为可选命名方案

- 类型和名称空间 `UpperCamelCase` [`UpperCamelCase_UnderscoreTolerant`]
- 类型参数（模板） `TUpperCamelCase`
- 函数（成员） `UpperCamelCase`
- 本地变量（函数体内）`lowerCamelCase`
- 本地常量（函数体内）`lowerCamelCase`
- 方法参数（函数体内）`lowerCamelCase`
- 公有实例字段（成员）`UpperCamelCase` [`UpperCamelCase_UnderscoreTolerant`]
- 私有实例字段（成员）`_lowerCamelCase `  [`_lowerCamelCase_underscoreTolerant`]
- 公有静态字段（成员）`UpperCamelCase`  [`UpperCamelCase_UnderscoreTolerant`]
- 私有静态字段（成员）`_lowerCamelCase`  [`_lowerCamelCase_underscoreTolerant`]
- 常量字段（成员）`UpperCamelCase`  [`UpperCamelCase_UnderscoreTolerant`]
- 枚举成员 `UpperCamelCase`
- 本地方法 `UpperCamelCase`
- 其他实体 `UpperCamelCase`

## Git-Commit

- feat: 新功能
- fix: 修复bug
- docs: 文档
- refactor: 代码重构
- test: 测试用例
- chore: 其他修改，例如构建流程、依赖管理
- scope: commit影响的范围，例如Utils, Build...
- subject: commit的概述，建议符合50/72 formatting
- body: commit具体修改内容，可以分为多行，建议符合50/72 formatting
- footer: 一些备注，通常是 BREAKING CHANGE 或修复bug的链接
