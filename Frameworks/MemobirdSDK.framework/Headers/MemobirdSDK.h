//
//  MemobirdSDK.h
//  SDKDemo
//
//  Created by vison on 2018/9/3.
//  Copyright © 2018年 vison. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "MemobirdObject.h"

/**
 @brief 打印结果失败原因

 - MemobirdPrintTaskErrorUnauthorized: 未认证身份
 - MemobirdPrintTaskErrorBluetoothStatePoweredOff: 用户设备蓝牙未开启
 - MemobirdPrintTaskErrorBluetoothConnectFailed: 打印机蓝牙连接失败
 - MemobirdPrintTaskErrorContentError: 错误的打印内容
 */
typedef NS_ENUM(NSInteger, MemobirdPrintTaskError) {
    MemobirdPrintTaskErrorUnauthorized,
    MemobirdPrintTaskErrorBluetoothStatePoweredOff,
    MemobirdPrintTaskErrorBluetoothConnectFailed,
    MemobirdPrintTaskErrorContentError
};

/**
 @brief 定义了关于扫描到Memobird蓝牙设备以及打印失败的回调方法
 */
@protocol MemobirdSDKDelegate <NSObject>

/**
 @brief 扫描到一个Memobird蓝牙设备

 @param peripheral 扫描到的Memobird蓝牙设备对象
 @param macAddress 扫描到的Memobird蓝牙设备的mac地址
 */
- (void)didDiscoverMemobirdPeripheral:(CBPeripheral *)peripheral peripheralMacAddress:(NSString *)macAddress;

/**
 @brief 打印失败

 @param error 失败的原因
 */
- (void)requestMemobirdPrintTaskFailed:(MemobirdPrintTaskError)error;

@end

@interface MemobirdSDK : NSObject

@property (nonatomic, weak) id <MemobirdSDKDelegate> delegate;

+ (instancetype)defaultManager;

/**
 @brief 通过使用在Memobird开发平台申请的appkey，启动Memobird服务

 @param appKey 申请得到的应用密钥
 @note 请保证appKey与bundleID相对应，若错误将导致认证失败，无法使用SDK提供的功能
 */
- (void)startMemobirdSDKWithAppKey:(nonnull NSString *)appKey;

/**
 @brief 返回当前用户手机设备的蓝牙状态
 */
- (CBManagerState)currentDeviceBluetoothState;

/**
 @brief 启动扫描Memobird打印机设备

 @note 当扫描到设备时将回调didDiscoverMemobirdPeripheral:方法，你需要从扫描到的设备对象中以及mac地址分辨并选取你所需要用来打印的设备对象，再进行打印操作，请记得先开启Memobird打印机电源
 */
- (void)startScanMemobirdDevice;

/**
 @brief 停止扫描Memobird打印机设备
 */
- (void)stopScanMemobirdDevice;

/**
 @brief 打印单个纯文本内容

 @param text 文本内容
 @param peripheral 指定的Memobird打印机对象
 */
- (void)printTaskWithText:(NSString *)text memobirdPeripheral:(CBPeripheral *)peripheral;

/**
 @brief 打印单张图片内容

 @param image 图片内容
 @param peripheral 指定的Memobird打印机对象
 */
- (void)printTaskWithImage:(UIImage *)image memobirdPeripheral:(CBPeripheral *)peripheral;

/**
 @brief 同时打印多数内容

 @param contents 打印内容
 @param peripheral 指定的Memobird打印机对象
 @note 此接口可支持图文混排，将按索引顺序从上到下进行排列，内容数组应当存放提供的MemobirdOjbject对象，对象如何生成请到MemobirdObject文件中了解
 */
- (void)printTaskWithContents:(NSArray <BaseContent *> *)contents memobirdPeripheral:(CBPeripheral *)peripheral;

/**
 @brief 当前SDK版本号
 */
+ (NSString *)version;

@end
