/*
The stucture of petrol pump
struct petrolPump{
    int petrol;
    int distance;
};
*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int start = 0;
       int balance = 0;
       int deficit = 0;
       for(int i = 0 ; i < n ; i++){
           balance = balance + p[i].petrol - p[i].distance;
           if(balance < 0){
               //Negactive balanace
               // Step 1: Calculate how much deficiency of petrol is there
               deficit = deficit + balance;
               // Step 2: Take start to next block
               start = i+1;
               // Step 3: Make initial balanace again 0
               balance = 0;
           }
       }
       // Step 4: Find remaining petrol after visiting last block
       int remaining_petrol = deficit + balance;
       if(remaining_petrol > 0){
           //Travel is possible
           return start;
       }
       else{
           return -1;
       }
    }
};
