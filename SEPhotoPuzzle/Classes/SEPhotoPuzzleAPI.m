//
//  SEPhotoPuzzleAPI.m
//  SEPhotoPuzzleLib
//
//  Created by wenchang on 2020/12/21.
//

#import "SEPhotoPuzzleAPI.h"
#import "MeituEditStyleViewController.h"
#import "LoadingViewManager.h"
@implementation SEPhotoPuzzleAPI

+ (void)presentPhotoPuzzleWithImages:(NSArray <UIImage *>*)images superViewController:(UIViewController *)controller saveSuccess:(void(^)(UIImage * image))saveSuccess
{
    if (images.count < 2)
    {
        [[LoadingViewManager sharedInstance] showHUDWithText:@"至少选择两张图片" inView:controller.view duration:1.5f];
        return;
    }
    
    MeituEditStyleViewController *editController = [[MeituEditStyleViewController alloc] init];
    editController.images = images.copy;
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:editController];
    
    navController.modalPresentationStyle = UIModalPresentationOverFullScreen;
    [controller presentViewController:navController animated:YES completion:nil];

    //    __weak typeof (editController) weakEditController = editController;
    [LoadingViewManager sharedInstance].handleBlock = ^(UIImage *image) {
        saveSuccess(image);
        [navController.presentingViewController dismissViewControllerAnimated:NO completion:nil];
    };
}

@end

