#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "Windows.h" 


// Her soru ayri struct dizilerine alinmistir.
 struct questions{
		int id;
	        char soruMetni[150];
        	char butonA[75];
	        char butonB[75];
		char butonC[75];
		char butonD[75];
		char dogruc[75];

 };

 struct username{
	
 int skor;
 char name[20];	
	
 };
 // Ustteki struct yapisinden farkli olarak sorular tek struct yapisinda
 // donusumlu olarak tutulup dosyaya yazilmistir.
 struct sorular {

		int id;
	        char soruMetni[150];
       	        char butonA[75];
	        char butonB[75];
		char butonC[75];
		char butonD[75];
		char dogruc[75];

 };

 struct questions quest[20];
 struct username user[20];
 struct sorular sor;


 int geri;
 int score;



 int manu();
 void ekle();
 void sorusil();
 void sorugoster();
 void guncelle();
 int soruAta();
 void oyunOyna();
 void highscore();
 int skorAta();
 void bubblesort();


 void main(){

	do{
	
	int secenek = manu();
        system("cls");
    
    switch(secenek){
	
     case 1: //Soru ekle.
  
	ekle();
	
	system("cls");
        break;
   

     case 2: //Sorulari goster ve sil.
    	
	sorusil();
        system("cls");
	break;
	
     case 3: //Sorulari goster ve guncelle.
		    
	guncelle();
	system("cls");
	break;
		
     case 4: 
		    
	oyunOyna();
	system("cls");
	break;
	
     case 5: // Skor tablosu gosterilir.
		    
        bubblesort();
	system("cls");
	break;
	
     case 6: 
		    
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                              Islemiz uzerinde calisiyoruz...    \n");
	sleep(2);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                                               Cikis icin bir tusa basiniz...  \n\n\n\n\n\n\n\n\n\n\n\n");
	sleep(1);
	exit(0);
	//Çıkış
	break;
	
 }

 }while(geri == 0) ;

	return;
}


 int manu(){

    int secenek;

        printf("\n");
        printf("                                        ___________________________________                                               \n");
  	printf("=====================================> |   KIMDIR /NEDIR ?' E HOSGELDINIZ  | <=========================================\n");
  	printf("                                       |___________________________________|                                              \n");


   
	printf("                                          Soru ekle ..................(1)\n");
	printf("                                          Soru  sil ..................(2)\n");
        printf("                                          Sorulari goster ve guncelle.(3)\n");
	printf("                                          Oyun oyna ..................(4)\n");
	printf("                                          En yuksek skorlar ..........(5)\n");
	printf("                                          Cik ...(6)\n\n");
	printf(" ===================================================================================================================== \n");
	printf("                                          Yapmak istediginiz islemi secin: ");
	scanf("%d",&secenek);

	printf("\n");



	return secenek;

 } 

 void ekle(){
	
	FILE *sp;
	if ((sp = fopen("Sorular.txt","a")) == NULL)// Dosya acilir.
	printf("Dosya bulunamadi.\n");

	else{
	
 	printf("\n");
  	getchar();
        printf("  Soru ID: ");
        scanf("%d",&sor.id);
        printf("\n");
        getchar();
        printf("  Soru metni : \n");																
        printf("  ->  ");  fgets(sor.soruMetni,150,stdin);
	printf("\n  A: ");
        fgets(sor.butonA,75,stdin);
	printf("  B: ");
        fgets(sor.butonB,75,stdin);
	printf("  C: ");
	fgets(sor.butonC,75,stdin);
	printf("  D: ");
	fgets(sor.butonD,75,stdin);
	
	printf("\n  Dogru cevabi tumuyle yaziniz: "); 
	fgets(sor.dogruc,75,stdin);
	fprintf(sp, "%d\n%s%s%s%s%s%s",sor.id,sor.soruMetni,sor.butonA,sor.butonB,sor.butonC,sor.butonD,sor.dogruc); 
	/* Sorular structure inda tutulan sorular 
	sp pointer inin tuttugu dosyaya yazilir.*/
 }

	fclose(sp);
		
	printf("\n" );
	printf("  \033[32mSorunuz basarili bir sekilde kaydedilmistir ! \033[0m  \n\n");
	printf(" \033[31m--\033[0m> Geri \033[31m[\033[0m0\033[31m]\033[0m:  " );
	scanf("%d",&geri);
 }


 void sorusil(){ 
        sorugoster(); // Fonksiyondaki ifadeler bu fonksiyon icin de gecerlidir.
  
        FILE* ptr = fopen("Sorular.txt","r"); 
        FILE* ptr2 = fopen("Sorular2.txt","w");
   
 
        char line[256];
	int lineCounter=0; 
	printf("\n");
        printf("  Soru listesinde kacinci satirdaki soruyu silmek istiyorsunuz : ");
        int option=0;
 	scanf("%d",&option);
	printf(" \033[32m Isleminiz onaylanmistir ... \033[0m");
		
	while(fgets(line,sizeof(line),ptr)){
		
		if(lineCounter >= (option-1)*7 && lineCounter < option*7)
		{
		// Yazilan her soru dosyada 7 satir yer kaplar
		
		/* 
		ID
		Soru
		A
		B
		C
		D
		Dogru cevap 
		*/ 	
		
		/* option degiskeni silinecek soruyu tutar 
		yazilan bu program satir bazli calistigi icin silinecek soru-1 * 7 ile soru * 7
		satirlari arasinda kaliyor */ 
		}
		else{
			
		fprintf(ptr2,"%s",line);
	    /*
	     boylece bu aralikatki soru atlanarak 
		satir bazli taranan sorular konsola ve baska bir dosyaya  yazdirilir.
		*/ 
          
    	}
		lineCounter++;
			
    }
		
        fclose(ptr);
        fclose(ptr2);
	remove("Sorular.txt"); // Onceki dosya silinir. 
	rename("Sorular2.txt","Sorular.txt"); 
	
	/* Yeni dosya onceki dosya ismi ile yeniden 
	  isimlendirilir ve bu yontem ile atlanan satirdaki soru silinmis olur. 
	  */

	  
	printf("\n\n" );
	printf(" \033[31m--\033[0m> Ana menu icin Geri \033[31m[\033[0m0\033[31m]\033[0m:  " );
	scanf("%d",&geri);

    }

    
 void sorugoster(){
    	
   FILE* ptr = fopen("Sorular.txt","r");
        char line[256]; /* Dosyadan [] icersinde yazili olan sayi kadar satir okunur. */
	int lineCounter=0; // 0. indisten satirlar okunur.
    while(fgets(line,sizeof(line),ptr)){
      	 printf("%s",line); // Sorular konsola yazdirilir.
    			
   		lineCounter++; // Satir sayisi arttirilir.	
    	}
    
    fclose(ptr);
    	
	}
	
 void guncelle(){
		
		 sorugoster();
		
		 FILE* ptr = fopen("Sorular.txt","r"); 
 		 FILE* ptr2 = fopen("Questions.txt","w");
   
 
   char line[256];
   int lineCounter=0;
	
  printf("\n    \033[31m  ________________________________________________________ \033[0m                                            \n");
  printf("   \033[31m  | \033[0m  NOT\033[31m:\033[0m Lutfen guncellemek istediginiz sorunun ID'sini \033[31m | \033[0m               \n");
  printf("==>\033[31m  | \033[0m      guncelleme esnasinda tekrar kullaniniz !        \033[31m | \033[0m                              \n");                                         
  printf("   \033[31m  |________________________________________________________| \033[0m                                             \n");
	
	    printf("  \n   Soru listesinde kacinci satirdaki soruyu guncellemek istiyorsunuz : ");
	    int option=0;
	    scanf("%d",&option);
		
		
	while(fgets(line,sizeof(line),ptr)){
		
		if(lineCounter >= (option-1)*7 && lineCounter < option*7)
		{
			
		}
		else{
			
		fprintf(ptr2,"%s",line);
	
          
    	}
			lineCounter++;		
	}
	
	
	
        fclose(ptr);
        fclose(ptr2);
	remove("Sorular.txt");
	rename("Questions.txt","Sorular.txt");
        system("cls");

	FILE *sp;
	if ((sp = fopen("Sorular.txt","a")) == NULL)
	printf("Dosya bulunamadi.\n");

	else{

	
        printf("\n");
        getchar();
        printf("  Soru ID: ");
        scanf("%d",&sor.id);
        printf("\n");
        getchar();
        printf("  Soru metni : \n");																
        printf("  ->  ");  fgets(sor.soruMetni,150,stdin);
	printf("\n  A: ");
        fgets(sor.butonA,75,stdin);
	printf("  B: ");
        fgets(sor.butonB,75,stdin);
	printf("  C: ");
	fgets(sor.butonC,75,stdin);
	printf("  D: ");
	fgets(sor.butonD,75,stdin);
	
	printf("\n  Dogru cevabi tumuyle yaziniz: ");
	fgets(sor.dogruc,75,stdin);
	fprintf(sp, "%d\n%s%s%s%s%s%s",sor.id,sor.soruMetni,sor.butonA,sor.butonB,sor.butonC,sor.butonD,sor.dogruc);

	
    	}

	fclose(sp);
				
	printf("\n" );
	printf("  \033[32mSorunuz basarili bir sekilde guncellenmistir ! \033[0m  \n\n");
	
	printf(" \033[31m--\033[0m>  Ana menu icin Geri \033[31m[\033[0m0\033[31m]\033[0m:  " );
	scanf("%d",&geri);
				
   }
    
 int soruAta(){// Oyun için sorular structure yapısına atanıyor
  
  	int soruSayisi = 0;
	FILE *file ;
  
  	if((file = fopen("Sorular.txt","r") )!= NULL){
  		while(!feof(file)){ /* Her soru ayri structure yapisina alinmistir */
			fscanf(file,"%d\n",&quest[soruSayisi].id);
			fgets(quest[soruSayisi].soruMetni,1024,file);
			fgets(quest[soruSayisi].butonA,1024,file);
			fgets(quest[soruSayisi].butonB,1024,file);
			fgets(quest[soruSayisi].butonC,1024,file);
			fgets(quest[soruSayisi].butonD,1024,file);
			fgets(quest[soruSayisi].dogruc,1024,file);
		
			soruSayisi++; 			
		  }
  		
	  }else{
	  	// Dosya bulunamadi...
	  }
	  return soruSayisi;
	  fclose(file);
  }
  
  
 void oyunOyna(){
  	
  	int soruSayisi = soruAta(); // Dosyadaki soru sayisi atanir.
  	int i,tur=1;
  	score=0;
  	char answers;
	   
  	
  	for(i=0;i<5;i++){
  	srand(time(NULL));
  	int ssayi ;		
        ssayi= 0 + rand() %(soruSayisi-1); // Her soru gecisinde rastgele soru secilir. 
  

        printf("\n");
        printf("\033[31m =====================================================>\033[0m | [%d/5] | \033[31m<==================================================== \033[0m \n",tur);
        printf("                                                                                \n");
  	printf(" Soru Metni: %s\n A: %s\n B: %s\n C: %s\n D: %s\n ",quest[ssayi].soruMetni,quest[ssayi].butonA,quest[ssayi].butonB,quest[ssayi].butonC,quest[ssayi].butonD);
  	printf("\033[31m==============================================\033[0m============<>============\033[31m============================================= \033[0m \n");
  	printf("  ----- \n");
        printf("\033[31m |\033[0m NOT \033[31m|\033[0m  -> Cevap kucuk \033[31m-\033[0m buyuk harfe duyarlidir !  \n");
        printf("  ----- \n");
        printf(" Cevap : ");
	  getchar();
	  scanf("%c",&answers);
	  if(answers == 'a'){ // Secilen soru satiri dogru cevap satiri ile eslenirse
	  	if(!strcmp(quest[ssayi].butonA,quest[ssayi].dogruc)){  // score +20 degerini alir. Bu nedenle  dogru cevap
	  		score+=20;                                         // dosyada her 7. satira eksiksiz yazilmalidir.
		  }
	  	
	  }
	  
	  else if(answers == 'b'){
	  	if(!strcmp(quest[ssayi].butonB,quest[ssayi].dogruc)){
	  		score+=20;
		  }
	  }
	  
	  
	  
	  else if(answers == 'c'){
	  	if(!strcmp(quest[ssayi].butonC,quest[ssayi].dogruc)){
	  		score+=20;
		  }
	  	
	  }
	  
	 else if(answers == 'd'){
	  	if(!strcmp(quest[ssayi].butonD,quest[ssayi].dogruc)){
	  		score+=20;
		  }
	  	
	  }
	  
	  printf("\nSonraki Soru ->\n");
	  
  	tur++;
	getch();	
  	system("cls");
  	

  }
  printf("\n\n\n\n\n\n                                                      \033[32m  Tebrikler !\033[0m\n");
  	printf("\n                                                     Oyun Skorunuz: %d\n ",score);
 
  	highscore();	

  	printf("\n\n\n\n\n\n\n" );
	printf(" \033[31m--\033[0m>  Ana menu icin Geri \033[31m[\033[0m0\033[31m]\033[0m:  " );
	scanf("%d",&geri);
		
  }
  
  
 void highscore(){
  	
  	FILE *f;
    int sa =0;
    score;
  	if((f= fopen(" Skorlar.txt ","a"))!=NULL){
	  printf("                                                    Kullanici adi: ");
	  
    scanf("%s",user[sa].name);
    getchar();
    user[sa].skor=score;
    fprintf(f,"%d\n%s\n",user[sa].skor,user[sa].name); // Kullanici skor ve isimi dosyaya yazdirilir.	
	
	  } 
	   	
  	else{
  		
  		//Dosya bulunamdi...
	  }
  	
  	fclose(f);
  	
  }
  
 int skorAta(){
 	
  	int kullanicis = 0;
  
  	FILE *fs ;
  
  	if((fs = fopen(" Skorlar.txt ","r"))!=NULL){
  		while(!feof(fs)){
			fscanf(fs,"%d\n%s\n",&user[kullanicis].skor,user[kullanicis].name);
			kullanicis++; 	// Skor ve isim sirasiyla structure dizilerinde tutulur.		
		  }
  		
	  }
	  else{
	  	// Dosya bulunamadi...
	  }
	  fclose(fs);
	  return kullanicis; /* Dosyadaki toplam isim(skor) sayisi 
	  bubblesort fonksiyonuna aktarilir. */
	  
  }
  
 void bubblesort( ){
  	
  	int q =skorAta();
  	
// Skorlar  buyukten kucuge siralanir. 	
  
  	int i = 0;
	int a = 0;

	for(i=0;i<q-1;i++){
		
		for(a=0;a<q-1;a++){
		
			if(user[a].skor > user[a+1].skor){
				int temp = user[a].skor;
				char tempName[50] ;
				strcpy (tempName,user[a].name);
				user[a].skor = user[a+1].skor;
				strcpy (user[a].name,user[a+1].name);
				strcpy (user[a+1].name,tempName);
				user[a+1].skor = temp;
			}
		}
	}
	printf("\n\n\n\n                                                    \033[31m  _____________ \033[0m \n");
  	printf("   ================================================>\033[31m |\033[0m SCORE TABLE \033[31m|\033[0m <============================================ \n");
  	printf("                                                    \033[31m |_____________| \033[0m\n\n\n");
   	 printf("                                                       1\033[31m-\033[0m %s\n                                                           %d\n",user[q-1].name,user[q-1].skor);
   	 printf("                                                       2\033[31m-\033[0m %s\n                                                           %d\n",user[q-2].name,user[q-2].skor);
  	printf("                                                       3\033[31m-\033[0m %s\n                                                           %d\n",user[q-3].name,user[q-3].skor);
  	printf("\n\n \033[31m  =========================================\033[0m===============================\033[31m======================================= \033[0m \n");
  	printf("\n\n\n\n\n \033[31m--\033[0m > Ana menu icin Geri \033[31m[\033[0m0\033[31m]\033[0m:  " );
	scanf("%d",&geri);
  	
  }
  	
  	
  	
