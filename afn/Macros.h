//
//  Macros.h
//  WZZCommon
//
//  Created by 王召洲 on 16/9/19.
//  Copyright © 2016年 wyzc. All rights reserved.
//

#ifndef Macros_h
#define Macros_h
//弱指针
#define WeakSelf(weakself) __weak __typeof(&*self)weakself = self;

#pragma Colre --颜色
// 固定色
#define kWhiteColor [UIColor whiteColor]
#define kBlackColor [UIColor blackColor]
#define kDarkGrayColor [UIColor darkGrayColor]
#define kLightGrayColor [UIColor lightGrayColor]
#define kGrayColor [UIColor grayColor]
#define kRedColor [UIColor redColor]
#define kGreenColor [UIColor greenColor]
#define kBlueColor [UIColor blueColor]
#define kCyanColor [UIColor cyanColor]
#define kYellowColor [UIColor yellowColor]
#define kMagentaColor [UIColor magentaColor]
#define kOrangeColor [UIColor orangeColor]
#define kPurpleColor [UIColor purpleColor]
#define kBrownColor [UIColor brownColor]
#define kClearColor [UIColor clearColor]

//随机色
#define kRandomeColor [UIColor colorWithRed: arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue: arc4random_uniform(256)/255.0 alpha:1 ]
//自定义色
#define kRGBAlpha(r,g,b,a) [UIColor colorWithRed:(r) green:(g) blue:(b) alpha:(a)]
#define kRGB(r,g,b) kRGBAlpha(r,g,b,1)

// 十六进制色
#define kHEXRGBAlpha(r,g,b,a) kRGBAlpha(r/255.0,g/255.0,b/255.0,a)
#define kHEXRGB(r,g,b) kRGBAlpha(r/255.0,g/255.0,b/255.0,1)

//本项目用色-字体颜色
#define kFontColorBlue kHEXRGB(43.0,178.0,233.0)
#define kFontColorGreen kHEXRGB(0,182,65)
#define kFontColorBlack kHEXRGB(0,0,0)
#define kFontColorBlackDark kHEXRGB(64,64,64)
#define kFontColorGray kHEXRGB(153,153,153)
#define kFontColorGrayDrak kHEXRGB(115,115,115)
#define kFontColorGrayShallow kHEXRGB(210,210,210)
#define kFontColorWhite kHEXRGB(255,255,255)

//本项目用色-图标颜色
#define kIconBlue kHEXRGB(43,177,233)
#define kIconYellow kHEXRGB(255,159,59)
#define kIconGreen kHEXRGB(139,195,74)
#define kIconRed kHEXRGB(255,59,48)

//字体
//系统字体
#define kFontSystem [UIFont systemFontSize]
#define kFontSize(size) [UIFont systemFontOfSize:(size)]
#define kBoldFont(size) [UIFont boldSystemFontOfSize:(size)]
#define kScreenScale ([[UIScreen mainScreen] scale])
//字体单位 pixel
#define kFont(f) kFontSize((f)/kScreenScale)
//项目用字体
#define kFont62 kFont(62)
#define kFont26 kFont(26)
#define kFont22 kFont(22)
#define kFont18 kFont(18)

//系统字体-样式
#define kFontHeadline [UIFont preferredFontForTextStyle:UIFontTextStyleHeadline]
#define kFontSubheadline [UIFont preferredFontForTextStyle:UIFontTextStyleSubheadline]
#define kFontFootnote [UIFont preferredFontForTextStyle:UIFontTextStyleFootnote]
#define kFontCaption1 [UIFont preferredFontForTextStyle:UIFontTextStyleCaption1]
#define kFontCaption2 [UIFont preferredFontForTextStyle:UIFontTextStyleCaption2]
#define kFontTitle1   [UIFont preferredFontForTextStyle:UIFontTextStyleTitle1]
#define kFontTitle2   [UIFont preferredFontForTextStyle:UIFontTextStyleTitle2]
#define kFontTitle3   [UIFont preferredFontForTextStyle:UIFontTextStyleTitle3]
#define kFontBody     [UIFont preferredFontForTextStyle:UIFontTextStyleBody]
#define kFontCallout  [UIFont preferredFontForTextStyle:UIFontTextStyleCallout]


// 系统UI
#pragma SystemUI

#define kNavigationBarHeight 44
#define kStatusBarHeight 20
#define kTopBarHeight 64
#define kToolBarHeight 44
#define kTabBarHeight 49
#define kiPhone4_W 320
#define kiPhone4_H 480
#define kiPhone5_W 320
#define kiPhone5_H 568
#define kiPhone6_W 375
#define kiPhone6_H 667
#define kiPhone6P_W 414
#define kiPhone6P_H 736

#define KSelfWidth (self.bounds.size.width)
#define KSelfHeight (self.bounds.size.height)
// 当前屏幕宽和高
#define kScreenWidth  ([[UIScreen mainScreen] bounds].size.width)
#define kScreenHeight  ([[UIScreen mainScreen] bounds].size.height)

// 日志输出
#if DEBUG
#define MYLog(...) NSLog(__VA_ARGS__)
#else 
#define MYLog(...) {}
#endif


//沙河
#define kdoc NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).lastObject

#define klib NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES).lastObjec

#define kcach NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).lastObject

#define kpre NSSearchPathForDirectoriesInDomains(NSPreferencePanesDirectory, NSUserDomainMask, YES).lastObject

#define  ktem   NSSearchPathForDirectoriesInDomains(NSTemporaryDirectory(), NSUserDomainMask, YES).lastObject

#endif /* Macros_h */
