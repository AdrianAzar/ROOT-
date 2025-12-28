

void graphfctarr(){

     const int N = 5;
     double x[5]={1,5,7,13,17};
     double y[5];
 
     
     //loop
     for(int i =0; i< N; i++){
     				 //change depending on what you want
     	y[i] = pow(10, -x[i]);
          
     }
     
     TGraph *gr = new TGraph(N, x, y);
     
     TCanvas *cv1 = new TCanvas("cv1", "Decay", 800, 600);
     cv1-> SetLogy(); //y axis log scale
     
     gr -> GetXaxis()-> SetLimits(0,20);
     gr -> GetYaxis()-> SetRangeUser(1e-8,1);
     
     gr -> SetTitle("Plot");
     gr -> Draw("APL"); //Axes-Points-Line
}
