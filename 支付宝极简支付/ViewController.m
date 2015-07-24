//
//  ViewController.m
//  支付宝极简支付
//
//  Created by marks on 15/5/27.
//  Copyright (c) 2015年 zhangguobing. All rights reserved.
//

#import "ViewController.h"
#import "GBAlipayManager.h"

@interface ViewController ()

@end

@implementation ViewController
-(void)dealloc{
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    
}
- (void)viewDidLoad {
    [super viewDidLoad];

    UIButton*pay=[UIButton buttonWithType:UIButtonTypeCustom];
    pay.frame=CGRectMake(100, 100, 100, 40);
    pay.backgroundColor=[UIColor orangeColor];
    [pay setTitle:@"支付宝" forState:UIControlStateNormal];
    [pay setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [pay addTarget:self action:@selector(alipay) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:pay];
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(dealAlipayResult:) name:@"alipayResult" object:nil];
}
-(void)dealAlipayResult:(NSNotification*)notification{
    NSString*result=notification.object;
    
    if([result isEqualToString:@"9000"]){
        
        NSLog(@"支付成功");
        
        
    }else{
        
        NSLog(@"支付失败");
    }
    
    
    
}
-(void)alipay{
    
    NSLog(@"支付宝支付");
    [GBAlipayManager alipayWithProductName:@"雅思" amount:@"0.01" tradeNO:[self generateTradeNO] notifyURL:@"www.baidu.com" productDescription:@"雅思全套书籍" itBPay:@"30"];

    
}
#pragma mark   ==============产生随机订单号==============


-(NSString *)generateTradeNO
{
    static int kNumber = 15;
    
    NSString *sourceStr = @"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    NSMutableString *resultStr = [[NSMutableString alloc] init];
    srand(time(0));
    for (int i = 0; i < kNumber; i++)
    {
        unsigned index = rand() % [sourceStr length];
        NSString *oneStr = [sourceStr substringWithRange:NSMakeRange(index, 1)];
        [resultStr appendString:oneStr];
    }
    return resultStr;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
