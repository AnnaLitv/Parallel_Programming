with Ada.Text_IO; 
use Ada.Text_IO;
with Ada.Integer_Text_IO; 
use Ada.Integer_Text_IO;


procedure First_Ada is

    
    task F1;
    
    task body F1 is
	N, MIN	:Integer;
	type A is array (1..100) of Integer;
	type B is array (1..100) of Integer;
	type C is array (1..100) of Integer;
	subtype ind  is Integer range 1..100;
	type  MA  is array (ind, ind) of Integer;
	type  MD  is array (ind, ind) of Integer;

	MA_V  : MA := ( others => (others => 0) );
	MD_V  : MD := ( others => (others => 0) );
	
	type  FI  is array (ind, ind) of Integer;
	type  SE  is array (ind, ind) of Integer;

	FI_V  : FI := ( others => (others => 0) );
	SE_V  : SE := ( others => (others => 0) );
	
	A_V	  : A  ;
	B_V	  : B  ;
	C_V	  : C  ;
    begin 
			delay 1.0;
            Put_Line("task 1 started!");
			
			Put_Line("Enter the N: ");
			Get(N);
			Put_Line("Enter the vector B: "); --вводим вектор В
			for  ind in 1..N loop
				Get(B_V(ind));
			end loop;
			--for  ind in 1..N loop
				--Put(B_V(ind));
			--end loop;
			Put_Line("Enter the vector C: "); --вводим вектор С
			for  ind in 1..N loop
				Get(C_V(ind));
			end loop;
			Put_Line("Enter the matrix MA: "); --вводим матрицу МА
			for  ind in 1..N loop
			Put_Line("Enter the new line");
			for  indx in 1..N loop
				Get(MA_V(ind,indx));
			end loop;
			end loop;
			
			
			for  ind in 1..N loop --показываем матрицу МА
			for  indx in 1..N loop
				Put(MA_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			
			
			Put_Line("Enter the matrix MD: "); --вводим матрицу МD
			for  ind in 1..N loop
			Put_Line("Enter the new line");
			for  indx in 1..N loop
				Get(MD_V(ind,indx));
			end loop;
			end loop;
			
			for  ind in 1..N loop --показываем матрицу MD
			for  indx in 1..N loop
				Put(MD_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			
			--узнаем минимальный эллемент в векторе С
			MIN:=C_V(1);
			for ind in 2..N loop
			if MIN>C_V(ind) then
			MIN:=C_V(ind);
			end if;
			end loop;
			--умножаем вектор В на минимальный
			for ind in 1..N loop
			B_V(ind):=B_V(ind)*MIN;
			end loop;
			--перемножение двух матриц MA и MD
			for i in 1..N loop
				for j in 1..N loop
						FI_V(i, j):=0;
						for k in 1..N loop
						FI_V(i,j):=FI_V(i,j)+MA_V(i,k)*MD_V(k,j);
						end loop;
					end loop;
			end loop;
			--показываем матрицу FI
			Put_Line("Mult of MA & MD :");
			for  ind in 1..N loop 
			for  indx in 1..N loop
				Put(FI_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			--прибавляем к FI MD
			for  i in 1..N loop 
			for  j in 1..N loop
				FI_V(i,j):=FI_V(i,j)+MD_V(i,j);
			end loop;
			end loop;
			--показываем матрицу FI
			Put_Line("Sum of FI&MD :");
			for  ind in 1..N loop 
			for  indx in 1..N loop
				Put(FI_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			--умножаем вектор на матрицу
			for i in 1..N loop
			for j in 1..N loop
			A_V(i):=A_V(i)+FI_V(i,j)*B_V(j);
			end loop;
			end loop;
			--
			for i in 1..N loop
			Put(A_V(i));
			end loop;
			Put_Line(" ");
			Put_Line("task 1 finished!");
			
    end F1;

  
    task F2 ;

    task body F2 is
	N, T:Integer;
	subtype ind  is Integer range 1..100;
	type  MA  is array (ind, ind) of Integer;
	type  MD  is array (ind, ind) of Integer;
	type  MZ  is array (ind, ind) of Integer;
	type  MB  is array (ind, ind) of Integer;
	
	MA_V  : MA := ( others => (others => 0) );
	MD_V  : MD := ( others => (others => 0) );
	MZ_V  : MZ := ( others => (others => 0) );
	MB_V  : MB := ( others => (others => 0) );
	
	type  FI  is array (ind, ind) of Integer;
	type  SE  is array (ind, ind) of Integer;
	type  TH  is array (ind, ind) of Integer;
	type  MK  is array (ind, ind) of Integer;
	
	MK_V  : MK := ( others => (others => 0) );
	FI_V  : FI := ( others => (others => 0) );
	SE_V  : SE := ( others => (others => 0) );
	TH_V  : TH := ( others => (others => 0) );
	
    begin 
			delay 30.0;
            Put_Line("task 2 started!");
			Put_Line("Enter the N: "); --ввoдим N
			Get(N);
			Put_Line("Enter the matrix MA: "); --вводим матрицу МА
			for  ind in 1..N loop
			Put_Line("Enter the new line");
			for  indx in 1..N loop
				Get(MA_V(ind,indx));
			end loop;
			end loop;
			for  ind in 1..N loop --показываем матрицу МА
			for  indx in 1..N loop
				Put(MA_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			Put_Line("Enter the matrix MZ: "); --вводим матрицу МZ
			for  ind in 1..N loop
			Put_Line("Enter the new line");
			for  indx in 1..N loop
				Get(MZ_V(ind,indx));
			end loop;
			end loop;
			for  ind in 1..N loop --показываем матрицу МZ
			for  indx in 1..N loop
				Put(MZ_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			Put_Line("Enter the matrix MB: "); --вводим матрицу МB
			for  ind in 1..N loop
			Put_Line("Enter the new line");
			for  indx in 1..N loop
				Get(MB_V(ind,indx));
			end loop;
			end loop;
				Put_Line("MB :"); --показываем матрицу МB
			for  ind in 1..N loop 
			for  indx in 1..N loop
				Put(MB_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			--умножаем МА*МА
			for i in 1..N loop
				for j in 1..N loop
						for k in 1..N loop
						MD_V(i,j):=MD_V(i,j)+MA_V(i,k)*MA_V(k,j);
						end loop;
					end loop;
			end loop;
			Put_Line("MA * MA:");
			for  ind in 1..N loop 
			for  indx in 1..N loop
				Put(MD_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			--умножаем МА*МА*MZ
			for i in 1..N loop
				for j in 1..N loop
						for k in 1..N loop
						FI_V(i,j):=FI_V(i,j)+MD_V(i,k)*MZ_V(k,j);
						end loop;
					end loop;
			end loop;
			Put_Line("MULT of MA*MA*MZ :");
			for  ind in 1..N loop 
			for  indx in 1..N loop
				Put(FI_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			
		
			--транспонируем МВ
			for i in 1..N loop
			for j in 1..N loop
			begin
			TH_V(i,j):=MB_V(j,i);
			TH_V(j,i):=MB_V(i,j);		
			end;
			end loop;
			end loop;
			--
			Put_Line("Trans :");
			for  ind in 1..N loop 
			for  indx in 1..N loop
				Put(TH_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			--сумма матриц
			for  i in 1..N loop 
			for  j in 1..N loop
				MK_V(i,j):=TH_V(i,j)+FI_V(i,j);
			end loop;
			end loop;
			--
			Put_Line("MK :");
			for  ind in 1..N loop 
			for  indx in 1..N loop
				Put(MK_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			
			Put_Line("task 2 finished!");
    end F2;

	
	task F3 ;

    task body F3 is
	N, BUF:Integer;
	type R is array (1..100) of Integer;
	type S is array (1..100) of Integer;
	type O is array (1..100) of Integer;
	subtype ind  is Integer range 1..100;
	type  MT  is array (ind, ind) of Integer;
	type  MP  is array (ind, ind) of Integer;

	MT_V  : MT := ( others => (others => 0) );
	MP_V  : MP := ( others => (others => 0) );
	
	type  FI  is array (ind, ind) of Integer;
	type  SE  is array (ind, ind) of Integer;

	FI_V  : FI := ( others => (others => 0) );
	SE_V  : SE := ( others => (others => 0) );
	
	R_V	  : R  ;
	S_V	  : S  ;
	O_V	  : O  ;
    begin 
			delay 60.0;
            Put_Line("task 3 started!");
			Put_Line("Enter the N: "); --ввoдим N
			Get(N);
			Put_Line("Enter the vector C: "); --вводим вектор R
			for  ind in 1..N loop
			Get(R_V(ind));
			end loop;
			Put_Line("Enter the vector C: "); --вводим вектор S
			for  ind in 1..N loop
			Get(S_V(ind));
			end loop;
			Put_Line("Enter the matrix MA: "); --вводим матрицу МT
			for  ind in 1..N loop
			Put_Line("Enter the new line");
			for  indx in 1..N loop
			Get(MT_V(ind,indx));
			end loop;
			end loop;
			for  ind in 1..N loop --показываем матрицу МT
			for  indx in 1..N loop
			Put(MT_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			Put_Line("Enter the matrix MZ: "); --вводим матрицу МP
			for  ind in 1..N loop
			Put_Line("Enter the new line");
			for  indx in 1..N loop
			Get(MP_V(ind,indx));
			end loop;
			end loop;
			for  ind in 1..N loop --показываем матрицу МP
			for  indx in 1..N loop
			Put(MP_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			--соединение векторов R&S
			for i in 1..N loop
			R_V(i):=R_V(i)+S_V(i);
			end loop;
			--сортировка вектора по возрастанию
			for i in 1..N loop
			for j in i+1..N loop
			if R_V(i)>R_V(j) then
			BUF:=R_V(i);
			R_V(i):=R_V(j);
			R_V(j):=BUF;
			end if;
			end loop;
			end loop;
			  
			 -- 
			 for i in 1..N loop
			  Put(R_V(i));
			  end loop;
			  --
            --умножение MT&MP
			for i in 1..N loop
				for j in 1..N loop
						for k in 1..N loop
						FI_V(i,j):=FI_V(i,j)+MT_V(i,k)*MP_V(k,j);
						end loop;
					end loop;
			end loop;
			--показываем матрицу FI
			Put_Line("MT*MP :");
			for  ind in 1..N loop 
			for  indx in 1..N loop
				Put(FI_V(ind,indx));
			end loop;
			Put_Line(" ");
			end loop;
			--матрица на вектор
			for i in 1..N loop
			for j in 1..N loop
			O_V(i):=O_V(i)+FI_V(i,j)*R_V(j);
			end loop;
			end loop;
			--
			for i in 1..N loop
			Put(O_V(i));
			end loop;
			Put_Line(" ");
			Put_Line("task 3 finished!");
        
    end F3;
	
begin 
Put_Line("Hello  " );
   
end First_Ada;
