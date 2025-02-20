/**
 * @param {string} queryIP
 * @return {string}
 */
var validIPAddress = function(queryIP) {
    let v4 = true;
    let v6 = true;

    const ipv4 = queryIP.split(".");
    const ipv6 = queryIP.split(":");

    if(ipv4.length != 4) v4 = false;

    for(const ip of ipv4){
            const regex = /^\d+$/;
            if(!regex.test(ip)){
                v4 = false;
                break;
            }
            if(+ip > 255 || +ip < 0){
                v4 = false;
                break;
            }
            if(ip.length > 1 && ip[0] == "0"){
                v4 = false;
                break;
            }
    }
    if(v4) return "IPv4";
    if(ipv6.length != 8) v6 = false;
    for(const ip of ipv6){
        if(ip.length < 1 || ip.length > 4){
            v6 = false;
            break;
        }
        const regex = /^[0-9a-fA-F]+$/;
        if(!regex.test(ip)){
            v6 = false;
            break;
        }
    }

    if(v6) return "IPv6";
    return "Neither";
};
