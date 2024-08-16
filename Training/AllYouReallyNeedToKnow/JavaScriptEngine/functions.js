export function power(a, b) {
    let ret = 1;
    for(  var i = 0; i < b ; i++){
        ret = ret * a;
    }
    return ret;
}
