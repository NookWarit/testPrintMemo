//
//  MemobirdObject.h
//  SDKDemo
//
//  Created by vison on 2018/9/21.
//  Copyright © 2018年 vison. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 @brief 打印内容基础类
 */
@interface BaseContent : NSObject

@end

/**
 @brief 打印内容文本类
 */
@interface ContentText : BaseContent

/**
 @brief 文本内容
 */
@property (nonatomic, copy) NSString *text;

/**
 @brief 是否添加下划线
 */
@property (nonatomic, assign) BOOL underline;

/**
 @brief 是否加粗
 */
@property (nonatomic, assign) BOOL bold;

/**
 @brief 对齐方式
 */
@property (nonatomic, assign) NSTextAlignment textAlignment;

/**
 @brief 工厂方法
 */
+ (id)contentWithText:(NSString *)text
            underline:(BOOL)underline
                 bold:(BOOL)bold
        textAlignment:(NSTextAlignment)textAlignment;

@end

/**
 @brief 打印结果失败原因

 - ImageFilterTypeNone:       默认效果
 - ImageFilterTypeWord:       文字效果
 - ImageFilterTypeBuff:       图像增强
 - ImageFilterTypeSketch:     素描效果
 - ImageFilterTypeEdge:       描边效果
 - ImageFilterTypeNeon:       反色效果
 - ImageFilterTypeThreshold:  喷墨效果
 - ImageFilterTypeNegative:   底片效果
 - ImageFilterTypeEmboss:     浮雕效果
 */
typedef NS_ENUM(NSUInteger, ImageFilterType) {
    ImageFilterTypeNone,
    ImageFilterTypeWord,
    ImageFilterTypeBuff,
    ImageFilterTypeSketch,
    ImageFilterTypeEdge,
    ImageFilterTypeNeon,
    ImageFilterTypeThreshold,
    ImageFilterTypeNegative,
    ImageFilterTypeEmboss
};

/**
 @brief 打印内容图片类
 */
@interface ContentImage : BaseContent

/**
 @brief 图片内容
 */
@property (nonatomic, strong) UIImage *image;

/**
 @brief 滤镜样式，默认不使用滤镜
 */
@property (nonatomic, assign) ImageFilterType filterType;

/**
 @brief 工厂方法
 */
+ (id)contentWithImage:(UIImage *)image
       imageFilterType:(ImageFilterType)filterType;


@end
