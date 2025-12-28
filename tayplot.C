//Exercise to draw the Radioactive Decay law in exact form and taylor series. Then we label the half life on the graph.

#include<TMath.h>

//Radioactive Decay law
void tayplot(){
     const int N = 100;      	
     double t[N], y_ex[N], y_tay[N];
     double tau = 2.0; //mean lifetime
     
     
     for(int i = 0; i<N; i++){
         
         t[i] = 5*i/(N-1);
         y_ex[i] = TMath::Exp(-t[i]/tau);   	//exact
        
     }
       
     int order = 5; 
     for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int n = 0; n <= order; n++) {
            sum += TMath::Power(-t[i]/tau, n) / (TMath::Factorial(n));
        }
        y_tay[i] = sum;
     }
      
        
     TGraph *g_ex = new TGraph(N, t, y_ex);
     TGraph *g_tay = new TGraph(N, t, y_tay);
         
     TCanvas *canv = new TCanvas();
     
     g_ex->SetMarkerStyle(3);   // points: '+'
     g_ex->SetMarkerColor(kRed);
     g_ex->SetTitle("Exponential Decay vs Taylor Expansion;t;N/N0");
     g_ex->Draw("AP");          // A=axes, P=points

     g_tay->SetLineColor(kBlue);  
     g_tay->SetLineWidth(2);
     g_tay->Draw("L SAME");     // continuous line

   
     double t_half = tau * TMath::Log(2);
     TLine *half_line = new TLine(t_half, 1e-4, t_half, 1.0); // y from small to max
     half_line->SetLineColor(kGreen+2);
     half_line->SetLineStyle(2); // dashed
     half_line->SetLineWidth(2);
     half_line->Draw();

    
     TLatex *tex = new TLatex();
     tex->SetTextColor(kGreen+2);
     tex->SetTextSize(0.04);
     tex->DrawLatex(t_half+0.1, 0.1, "t_{1/2}"); // adjust y position

    
     TLegend *leg = new TLegend(0.7,0.7,0.9,0.9);
     leg->AddEntry(g_ex,"Exact (points)","p");
     leg->AddEntry(g_tay,"Taylor (line)","l");
     leg->AddEntry(half_line,"Half-life","l");
     leg->Draw();

}
