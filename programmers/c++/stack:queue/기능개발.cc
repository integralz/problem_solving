function solution(progresses, speeds) {
    var answer = [];
    var siz = progresses.length;
    var que = 0;
    var cou = 0;
    var che = 0;
    while(1){
        while(progresses[que] < 100){
            for(var i = que; i < siz; ++i){
                progresses[i] += speeds[i];
            }
        }
        che = 0;
        for(var i = que; i < siz; ++i){
            if(progresses[i] >= 100){
                ++che;
                ++cou;
            }
            else{
                que = cou;
                answer.push(che);
                break;
            }
        }
        if(cou == siz){
            answer.push(che);
            break;
        }
    }
    
            
        
    
    return answer;
}