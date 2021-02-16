class cq():
    f=-1
    r=0
    s=5
    arr=[-5]*s
    def enq(self,ele):
        if(self.isfull()):
            print("Full")
            return
        self.arr[self.r]=ele
        if(self.f==-1): self.f=self.r #Initialising f - 1st ele
        self.r=self.r%self.s+1
        print(self.arr)
        if(self.r==5): self.r = 0
    def deq(self):
        if(self.isempty()): return "Empty"
        item = self.arr[self.f]
        self.arr[self.f] = -5
        self.f= self.f%self.s+1

        if(self.f==5): self.f = 0  #Circulating -- Modding doesnt get to 0
        if(self.f == self.r): self.f = -1 #Empty now -Last ele deleted.

        return item
    def isfull(self):
        if(self.r==self.f): return True
        return False
    def isempty(self):
        if(self.f==-1): return True
        return False

c = cq()

for i in range(6):
    c.enq(i)
    print(f'''Front {c.f} Rear {c.r} Item {c.deq()}''')

