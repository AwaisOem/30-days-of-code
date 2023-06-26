class LRU{
    constructor(size){
        this.maxsize = size;
        this.length = 0;
        this.cache = new Map();
    }
    getItem(key){
        if(!this.cache.has(key))
            return "Not Found"
        let r = this.cache.get(key);
        this.cache.delete(key);
        this.cache.set(key , r);
        return r;
    }
    putItem(key, value){
        if(this.cache.has(key)){
            this.cache.delete(key);
            this.length--;
        }
        if(this.length  <  this.maxsize)
            this.length++;
        else
            this.cache.delete(this.FTE);
        this.cache.set(key, value);
    }
    get FTE()
    {
return this.cache.keys().next().value;
    }
    print(){
        console.log("Size : " , this.length);
        console.log("Max Size : " , this.maxsize);
        console.log(this.cache);
    }
}




function main(){

    let cache = new LRU(10); 
    cache.putItem("Awais" , 20)
    cache.putItem("Ilyas" , 30)
    cache.putItem("Madani" , 40)
    cache.putItem("Makki" , 50)
    cache.putItem("Milad" , 60)
    cache.putItem("Saad" , 60)
    cache.putItem("Ismail" , 60)
    cache.putItem("Mubeen" , 60)
    cache.putItem("Ali" , 60)
    cache.putItem("Saqib" , 60)
    console.log(cache.getItem("Ilyas"));
    cache.print();
    cache.putItem("Saad" , 110)
    cache.putItem("Usman" , 120)
    cache.print();

}
main()