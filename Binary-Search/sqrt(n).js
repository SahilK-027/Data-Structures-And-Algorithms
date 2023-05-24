var mySqrt = function(x) {
    let s = 0;
    let e = Math.ceil(x/2);
    let m = parseInt(s + (e-s)/2);
    let possible_ans = -1;
    while(s <= e){
        if(m * m == x) return m;
        else if(m * m < x){
            possible_ans = m;
            s = m + 1;
        }
        else{
            e = m - 1;
        }
        m = parseInt(s + (e-s)/2);
    }
    return possible_ans;
};