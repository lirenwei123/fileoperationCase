//
//  ViewController.m
//  afn
//
//  Created by apple on 16/10/24.
//  Copyright © 2016年 wyzc_lrw. All rights reserved.
//


/**
 *  注意网址一定要有//。否则就取不到文件名
 *
 *  @return <#return value description#>
 */
#define uuu @"http://www.baidu.com"
#define www @"http://github.com"
#define vvv @"https://www.oschina.net"

#import "ViewController.h"
#import <AFNetworking.h>
#import "Macros.h"

@interface ViewController ()

@end

@implementation ViewController
{
    UILabel *inlable;
    NSString *test;
    
}
- (void)viewDidLoad {
    [super viewDidLoad];

    
}

-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    
    [self filecoppration:vvv];
    
    
}


-(void)configLable{
    UILabel *lable =[[UILabel alloc]initWithFrame:CGRectMake(0, 0, 300, 300)];
    lable.center=self.view.center;
    lable.backgroundColor =[UIColor grayColor];
    [self.view addSubview:lable];
    lable.textAlignment =NSTextAlignmentCenter;
    lable.numberOfLines =0;
    lable.textColor =[UIColor yellowColor];
    inlable =lable;
}

-(void)configafn:(NSString *)urlstr{
    [self configwlan:YES];
    [self configjuhua:YES];
    NSURLSession *session =[NSURLSession sharedSession];
    dispatch_async(dispatch_queue_create("que", DISPATCH_QUEUE_CONCURRENT), ^{
        
        [[session dataTaskWithURL:[NSURL URLWithString:urlstr] completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
            if (!error) {
                
                NSString *str =[[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];
                
                dispatch_async(dispatch_get_main_queue(), ^{
                    inlable.text =str;
                    [self configjuhua:NO];
                    inlable.userInteractionEnabled =NO;
                    self.view.userInteractionEnabled=NO;
                });

                NSString *path =kdoc;
                path =[path stringByAppendingPathComponent:test];
                NSLog(@"---------%@",path);
                BOOL  iswrite =    [str writeToFile:path atomically:YES encoding:NSUTF8StringEncoding error:nil];
                NSLog(@"写入文件---%@",iswrite?@"yes":@"no");
                //把path写入数据持久化
            NSUserDefaults *usedefault = [NSUserDefaults standardUserDefaults];
                [usedefault setValue:test forKey:test];
            }
            else{
                NSLog(@"数据请求错误");
                [self configjuhua:NO];
            }
        }]resume];

        
        
    }) ;
    
}

#pragma mark --监控网络情况
-(void)configwlan:(BOOL)yesorno{
    AFNetworkReachabilityManager *manager =[AFNetworkReachabilityManager sharedManager];
    if (yesorno) {
        [manager startMonitoring];
        //        AFNetworkReachabilityStatusUnknown
        //        AFNetworkReachabilityStatusNotReachable     = 0,
        //        AFNetworkReachabilityStatusReachableViaWWAN = 1,
        //        AFNetworkReachabilityStatusReachableViaWiFi = 2,
        switch (manager.networkReachabilityStatus) {
                
            case 0:
                NSLog(@"无连接");
                break;
            case 1:
                NSLog(@"4g");
                break;
            case 2:
                NSLog(@"wifi");
                break;
                
            default:
                NSLog(@" 未知网络");
                break;
        }
        
    }
    else{
        [manager stopMonitoring];
    }
}

-(void)configjuhua:(BOOL)yesorno{
    
    
    if (yesorno) {
        /**
         UIRefreshControl只能用在UItableview里
         */
//        UIRefreshControl *juhua =[[UIRefreshControl alloc]initWithFrame:CGRectMake(220, 30, 50, 50)];
        UIActivityIndicatorView *juhua =[[UIActivityIndicatorView alloc]initWithFrame:CGRectMake(220, 30, 50, 50)];
        juhua.backgroundColor =[UIColor greenColor];
        [self.view addSubview:juhua];
        juhua.color =[UIColor redColor];
        [juhua startAnimating];
        juhua.tag =1000;
    }else{
        UIActivityIndicatorView *juhua =[self.view viewWithTag:1000];
        [juhua stopAnimating];
        juhua =nil;
        [juhua removeFromSuperview];
    }
    
    
    
}


-(void)filecoppration:(NSString*)netstr{
    
    //这里来改变，当网址不一致的时候，保存数据的key也跟着改变，设置文件名和key时一致的，
   test = [netstr componentsSeparatedByString:@"/"][2];
    NSLog(@"test =%@",test);
    [self configLable];
     NSUserDefaults *usedefault = [NSUserDefaults standardUserDefaults];
   NSString *strname = [usedefault valueForKey:test];
    NSString *path =kdoc;
    if (strname) {
        path =[path stringByAppendingPathComponent:strname];
        NSLog(@"path =%@",path);
 
    //判断文件路径下的文件是否存在
        NSFileManager *filemanager =[ NSFileManager defaultManager];
    BOOL isexit =[filemanager fileExistsAtPath:path];
    NSLog(@"%@",isexit?@"文件已存在":@"文件不存在");
    if (isexit) {
        NSString *str =[NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
        
        inlable.text =str;
        MYLog(@"这是从沙河路径取得的内容");
    }
    }else{
        
        [self configafn:netstr];
    }

}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
