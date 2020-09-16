//
// Created by  lei on 2020/9/17.
//
//1.网络请求发送、接收成功  2.dns协议解析

//https://blog.csdn.net/xrfsycg/article/details/8663061

//1个小时，理解+代码实现

/**
 * 发送dns 请求（属于网络部分）
 * @param dns_name 名字
 * */
void send_dns_request(unsigned *host_name);

/**
 * 解析dns 请求
 * */
void parse_dns_request();


void send_dns_request(char *dns_name);

// dns 请求投
typedef struct dns_header_t {
    //ID 一个16位的ID，请求时指定这个ID，回应指返回相同的ID，用来标识同一个会话。
    unsigned int tid;
    //QR 占1位，0表示请求，1表示响应。
    unsigned int qr;
    //OPCODE 操作码占4位，0表示标准请求。
    unsigned int opcode;
    // 占1位。表示响应的服务器是否是权威DNS服务器。只在响应消息中有效
    unsigned int aa;
    // 占1位。指示消息是否因为传输大小限制而被截断
    unsigned int tc;
    // 占1位。该值在请求消息中被设置，响应消息复用该值。如果被设置，表示希望服务器递归查询。但服务器不一定支持递归查询。
    unsigned int rd;
    // 占1位。该值在响应消息中被设置或被清除，以表明服务器是否支持递归查询
    unsigned int ra;
    // 占3位。保留备用
    unsigned short z;
    /**
    * 占4位。该值在响应消息中被设置。取值及含义如下
    * 0：No error condition，没有错误条件；
    * 1：Format error，请求格式有误，服务器无法解析请求；
    * 2：Server failure，服务器出错。
    * 3：Name Error，只在权威DNS服务器的响应中有意义，表示请求中的域名不存在。
    * 4：Not Implemented，服务器不支持该请求类型。
    * 5：Refused，服务器拒绝执行请求操作。
    * 6~15：保留备用。
    */
    unsigned int rcode: 4;
    // 占16位（无符号）指明Question部分的包含的实体数量。
    unsigned short qdcount: 16;
    // 占16位（无符号）指明Answer部分的包含的RR（Resource Record）数量。
    unsigned short ancount: 16;
    // 占16位（无符号）指明Authority部分的包含的RR（Resource Record）数量。
    unsigned short nscount: 16;
    // 无符号16位整数表示报文附加段中的附加记录数
    unsigned short arcount: 16;

} DNS_HDR;

void send_dns_request(unsigned *host_name) {

}
