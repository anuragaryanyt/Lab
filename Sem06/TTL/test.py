class vehicle:
    def __init__(self,make,model,year):
        self.make=make
        self.model=model
        self.year=year

    def ShowDetails(self):
        print(f"{self.make} {self.model} {self.year}")

    def overload(self,other):
        print(f"{self.make} {self.model} + {other.make} {other.model}")

class Car(vehicle):
    def __init__(self,make,model,year,door,fuel):
        super().__init__(make,model,year)
        self.door=door
        self.fuel=fuel

    def show(self):
        details = super().ShowDetails()
        print(f"{details} No of doors: {self.door}, Type of vehicle: {self.fuel}")



v1=vehicle("Tata","nano",2010)
v2=vehicle("suzuki","swift",2009)
v3=vehicle("kia","seltos",2020)

v1.ShowDetails()
v2.ShowDetails()
v3.ShowDetails()
print("")
print("overloaded function--")
v1.overload(v2)
print("")

c1 = Car("Tesla", "Model 3", 2020, 4, "electric")
c2 = Car("Hyundai", "i20", 2018, 5, "petrol")
c1.show()
c2.show()
