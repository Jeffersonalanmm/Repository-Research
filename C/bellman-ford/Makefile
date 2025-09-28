compile:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 deepseek-r1-distill-llama-70b.c -o deepseek-r1-distill-llama-70b_run -lapr-1 -lgomp -lm
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 llama-3.3-70b-versatile.c -o llama-3.3-70b-versatile_run -lapr-1 -lgomp -lm
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 qwen-qwq-32b.c -o qwen-qwq-32b_run -lapr-1 -lgomp -lm
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 the-algorithms.c -o the-algorithms_run -lapr-1 -lgomp -lm