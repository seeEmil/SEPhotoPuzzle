//
//  TaskLoadingViewManager.h

//
//  Created by XiangqiTU on 4/22/13.
//  Copyright (c) 2013 Owen.Qin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MBProgressHUD.h"

typedef void(^HandleBlock)(UIImage *image);

@class MBProgressHUD;

#define k_networkfail_delay_time    2.5
#define k_signin_delay_time         1.5

#define k_notification_name_removeHUD @"k_notification_name_removeHUD"

@interface LoadingViewManager : NSObject

@property (nonatomic ,copy) HandleBlock handleBlock;

- (void)showHUDWithText:(NSString*)hudText inView:(UIView *)containerView duration:(float)duration;

- (void)showHUDWithText:(NSString *)hudText inView:(UIView *)containerView;
- (void)hideHUDWithText:(NSString *)hudText afterDelay:(float)timeInterval;

//直接移出
- (void)hideHUDAfterDelay:(float)timeInterval;

//
+ (LoadingViewManager*)sharedInstance;
+ (void)releaseInstance;

- (void)showLoadingViewInView:(UIView*)view withText:(NSString*)text;
- (void)removeLoadingView:(UIView*)view;
- (void)showLoadingViewInView:(UIView*)view withText:(NSString*)text viewTag:(int)viewTag;
- (void)removeLoadingView:(UIView*)view viewTag:(int)viewTag;


//Favorite
- (void)showText:(NSString *)hudText inView:(UIView *)containerView;

//Network Fail
- (void)showNetworkFailedText:(NSString *)hudText inView:(UIView *)containerView;


//sprite load
+ (void)showLoadViewWithText:(NSString *)text andShimmering:(BOOL)shimmering andBlurEffect:(BOOL)blur inView:(UIView *)view;
+ (void)showLoadViewInView:(UIView *)view;
+ (void)hideLoadViewInView:(UIView *)view;
@end

