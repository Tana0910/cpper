# コンパイルオプションを変数として定義する
gcc_options = -std=c++17 -Wall --pedantic-error

# ターゲット : 事前要件
# 	レシピ
# 注) レシピの直前には必ずタブスペースを書かなければならない

program : main.cpp all.h all.h.gch
	g++ $(gcc_options) -include all.h $< -o $@

all.h.gch : all.h
	g++ $(gcc_options) -x c++-header -o $@ $<

run : program
	./program

clean : program
	rm -f ./program
	rm -f ./all.h.gch

.PHONY : run clean
