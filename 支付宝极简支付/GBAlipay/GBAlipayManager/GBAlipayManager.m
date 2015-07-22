//
//  GBAlipayManager.m
//  支付宝极简支付
//
//  Created by marks on 15/6/3.
//  Copyright (c) 2015年 zhangguobing. All rights reserved.
//

#import "GBAlipayManager.h"

@implementation GBAlipayManager
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
                   itBPay:(NSString *)itBPay
{
    
    
    
    
    [self alipayWithPartner:partner
                     seller:seller
                    tradeNO:tradeNO
                productName:productName
         productDescription:productDescription
                     amount:amount
                  notifyURL:notifyURL service:@"mobile.securitypay.pay" paymentType:@"1"
               inputCharset:@"UTF-8"
                     itBPay:itBPay
                 privateKey:PartnerPrivKey
                  appScheme:kAppScheme];
    
}
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
                      itBPay:(NSString *)itBPay;{
    
    [self alipayWithPartner:PartnerID
                     seller:SellerID
                    tradeNO:tradeNO
                productName:productName
         productDescription:productDescription
                     amount:amount
                  notifyURL:notifyURL service:@"mobile.securitypay.pay" paymentType:@"1"
               inputCharset:@"UTF-8"
                     itBPay:itBPay
                 privateKey:PartnerPrivKey
                  appScheme:kAppScheme];
    
    
    
    
    
}

// 包含所有必要的参数
+ (void)alipayWithPartner:(NSString *)partner
                   seller:(NSString *)seller
                  tradeNO:(NSString *)tradeNO
              productName:(NSString *)productName
       productDescription:(NSString *)productDescription
                   amount:(NSString *)amount
                notifyURL:(NSString *)notifyURL
                  service:(NSString *)service
              paymentType:(NSString *)paymentType
             inputCharset:(NSString *)inputCharset
                   itBPay:(NSString *)itBPay
               privateKey:(NSString *)privateKey
                appScheme:(NSString *)appScheme {
    
    Order *order = [[Order alloc]init];
    order.partner = partner;
    order.seller = seller;
    order.tradeNO = tradeNO;
    order.productName = productName;
    order.productDescription = productDescription;
    order.amount = amount;
    order.notifyURL = notifyURL;
    order.service = service;
    order.paymentType = paymentType;
    order.inputCharset = inputCharset;
    order.itBPay = itBPay;
    
    
    // 将商品信息拼接成字符串
    NSString *orderSpec = [order description];
    
    // 获取私钥并将商户信息签名,外部商户可以根据情况存放私钥和签名,只需要遵循 RSA 签名规范, 并将签名字符串 base64 编码和 UrlEncode
    
    id<DataSigner> signer = CreateRSADataSigner(PartnerPrivKey);
    NSString *signedString = [signer signString:orderSpec];
    
    //将签名成功字符串格式化为订单字符串,请严格按照该格式
    NSString *orderString = nil;
    if (signedString != nil) {
        orderString = [NSString stringWithFormat:@"%@&sign=\"%@\"&sign_type=\"%@\"",
                       orderSpec, signedString, @"RSA"];
        
        [[AlipaySDK defaultService] payOrder:orderString fromScheme:appScheme callback:^(NSDictionary *resultDic) {
            NSLog(@"reslut = %@",resultDic);
        }];
        
        
    }

   

}
#pragma mark   ==============产生随机订单号==============


+(NSString *)generateTradeNO
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

@end
