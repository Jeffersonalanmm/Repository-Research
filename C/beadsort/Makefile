compile:
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 qwen-qwq-32b.c -o qwen-qwq-32b_run -lapr-1 -lgomp -lm
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 meta-llama-llama-4-maverick-17b-128e-instruct.c -o meta-llama-llama-4-maverick-17b-128e-instruct_run -lapr-1 -lgomp -lm
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 mistral-saba-24b.c -o mistral-saba-24b_run -lapr-1 -lgomp -lm
	/usr/bin/gcc -pipe -Wall -O3 -fomit-frame-pointer -march=native -fopenmp -D_FILE_OFFSET_BITS=64 -I/usr/include/apr-1.0 the-algorithms.c -o the-algorithms_run -lapr-1 -lgomp -lm