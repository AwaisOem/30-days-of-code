let l = console.log;
let  makeNodes =(nodes , AL)=>nodes.map(e=>AL.set(e,[]));
let makeEdges = function(edges ,AL){
    edges.forEach(([a,b])=> {
        AL.get(a).push(b);
        AL.get(b).push(a);
    });
}


let makeGraphByAdjancyList = function(nodes , edges){
    let AL =  new Map();
    makeNodes(nodes,AL);
    makeEdges(edges , AL);
    return AL;
}
let bfs  = function (start, dest, AL){
    let visited = new Set();
    let queue = [start];
    let txt  = null;
    while(queue.length > 0){
        let crr = queue.shift();
        if(!AL.has(crr)){
            return "Invalid Graph or input";
        }
        AL.get(crr).forEach(e=>{
            if(e==dest){
                txt = "Route Found";
            } 
            if(!visited.has(e)){
                visited.add(e);
                queue.push(e);
            }  
        })
    }
    return txt ?? "Route Not Found";
}
let dfs  = function(start , dest , AL , visited = new Set() ){
let txt = null;
    AL.get(start).forEach(e=>{
        if(e==dest)
            txt =  "Route Found"
        if(!visited.has(e)){
            visited.add(e);
            dfs(e,dest , AL , visited);
        }
    })
    return txt ?? "Route Not Found"
}

let main= function(){
    let airports = 'Karachi,Islamabad,Rawalpindi,Sargodha,Lahore,Queta'.split(',')
    let routes = [
        ["Karachi" , "Islamabad"],
        ['Islamabad','Rawalpindi'],
        ['Islamabad','Lahore'],
        ['Rawalpindi','Karachi'],
        ['Rawalpindi','Lahore'],
        ['Karachi','Lahore'],
        ['Sargodha' , 'Queta'],
    ]
    let AL = makeGraphByAdjancyList(airports , routes);
    l(dfs("Karachi","Islamabad" ,AL));
    l(bfs("Karachi","Sargodha" ,AL));
}
main();