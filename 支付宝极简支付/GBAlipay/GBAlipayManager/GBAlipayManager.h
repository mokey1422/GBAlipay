
//  GBAlipayManager.h
//  支付宝极简支付
//
//  Created by marks on 15/6/3.
//  Copyright (c) 2015年 zhangguobing. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GBAlipayConfig.h"
/**
 *  支付宝极简支付使用说明
 *1.首先将GBAlipay文件导入到工程里面
 *2.点击项目名称,点击“Build Phases”选项卡,在“Link Binary with Librarles” 选项中,新增“AlipaySDK.framework”和“SystemConfiguration.framework” 两个系统库文件。如果项目中已有这两个库文件,可不必再增加；
 *3.点击项目名称,点击“Build Settings”选项卡,在搜索框中,以关键字“search” 搜索,对“Header Search Paths”增加头文件路径:“$(SRCROOT)/项目名称/GBAlipay/Alipay”（注意：不包括引号，如果不是放到项目根目录下，请在项目名称后面加上相应的目录名）；
 *4.在本头文件中设置kPartnerID、kSellerAccount、kNotifyURL、kAppScheme和kPrivateKey的值（所有的值在支付宝回复的邮件里面：注意，建议除appScheme以外的字段都从服务器请求）；
 *5.点击项目名称,点击“Info”选项卡，在URL types里面添加一项，Identifier可以不填，URL schemes必须和appScheme的值相同，用于支付宝处理回到应用的事件；
 *6.在需要调用支付的界面直接包含头文件#import "GBAlipayConfig.h"，一句话调用方法即可，另外接收回调结果复制以下代码：
 viewDidLoad里面添加监听：
   [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(dealAlipayResult:) name:@"alipayResult" object:nil];
//移除监听
     -(void)dealloc{
     
     [[NSNotificationCenter defaultCenter] removeObserver:self];
     
     }
//监听处理事件
 -(void)dealAlipayResult:(NSNotification*)notification{
 NSString*result=notification.object;
 
 if([result isEqualToString:@"9000"]){
 
      NSLog(@"支付成功");
 
 }else{
 
      NSLog(@"支付失败");
 }

 
 }
 
 *7.别忘了在AppDelegate中处理事件回调（可直接复制下面内容）：
 - (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
 //如果极简 SDK 不可用,会跳转支付宝钱包进行支付,需要将支付宝钱包的支付结果回传给 SDK if ([url.host isEqualToString:@"safepay"]) {
 [[AlipaySDK defaultService] processOrderWithPaymentResult:url standbyCallback:^(NSDictionary *resultDic) {
 NSLog(@"result = %@",resultDic);
 //支付结果
 [[NSNotificationCenter defaultCenter]postNotificationName:@"alipayResult" object:[resultDic objectForKey:@"resultStatus"]];
 }];
 if ([url.host isEqualToString:@"platformapi"]){//支付宝钱包快登授权返回 authCode
 [[AlipaySDK defaultService] processAuthResult:url standbyCallback:^(NSDictionary *resultDic) {
 NSLog(@"result = %@",resultDic);
 }];
 }
 return YES;
 }
 *
 */
@interface GBAlipayManager : NSObject
/**
 *  针对多个用户用户配置信息请求自服务器
 *
 *  @param partner            合作者身份ID
 *  @param seller             卖家支付宝账号
 *  @param tradeNO            商户网站唯一订单号
 *  @param productName        商品名称
 *  @param productDescription 商品详情
 *  @param amount             总金额
 *  @param notifyURL          服务器异步通知页面路径
 *  @param itBPay             未付款交易的超时时间
 */
+ (void)alipayWithPartner:(NSString *)partner
                   seller:(NSString *)seller
                  tradeNO:(NSString *)tradeNO
              productName:(NSString *)productName
       productDescription:(NSString *)productDescription
                   amount:(NSString *)amount
                notifyURL:(NSString *)notifyURL
                   itBPay:(NSString *)itBPay;


/**
 *  只针对单一用户数据本地写死
 *
 *  @param productName        商品名称
 *  @param amount             商品金额
 *  @param notifyURL          服务器异步通知页面路径
 *  @param productDescription 商品详情
 *  @param itBPay             未付款交易的超时时间
 */
+(void)alipayWithProductName:(NSString *)productName
                      amount:(NSString *)amount
                     tradeNO:(NSString *)tradeNO
                   notifyURL:(NSString *)notifyURL
          productDescription:(NSString *)productDescription
                      itBPay:(NSString *)itBPay;


@end
