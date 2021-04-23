class A {
    set_var(num : Int) : SELF_TYPE {
	{
		a<-num*2;
		b<-3;
		c<-num;
		num<-num+1;
		d<-c*c;
		j<-num*2;
		e<-b*2;
		f<-a+d;
		g<-e*f;
		if g < num then
                     {x <- g - num;}
            	else
               	     {x <- num - g;}
            	fi;
            num <- x;
	} 
    };
};

