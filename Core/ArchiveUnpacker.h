#pragma once 
#include <minizip/unzip.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>

class ArchiveUnpacker {
public:
    ArchiveUnpacker(const std::string& archivePath, const std::string& password="")
        : archivePath(archivePath), password(password) {}

    bool Unpack() {
        unzFile zipfile = unzOpen(archivePath.c_str());
        if (!zipfile) {
            std::cerr << "Cannot open ZIP archive: " << archivePath << std::endl;
            return false;
        }

        if (unzGoToFirstFile(zipfile) != UNZ_OK) {
            std::cerr << "Cannot go to first file in ZIP archive." << std::endl;
            unzClose(zipfile);
            return false;
        }

        do {
            if (!UnpackCurrentFile(zipfile)) {

            }
        } while (unzGoToNextFile(zipfile) == UNZ_OK);

        unzClose(zipfile);
        return true;
    }

    std::vector<unsigned char> GetFile(const std::string& filePath) const {
        auto it = unpackedFiles.find(filePath);
        if (it != unpackedFiles.end()) {
            return it->second;
        }
        else {
            std::cerr << "File " << filePath << " not found in the archive." << std::endl;
            return {};
        }
    }

private:
    std::string archivePath;
    std::string password;
    std::map<std::string, std::vector<unsigned char>> unpackedFiles;

    bool UnpackCurrentFile(unzFile zipfile) {

        char filename[256];
        unz_file_info fileInfo;
        if (unzGetCurrentFileInfo(zipfile, &fileInfo, filename, sizeof(filename), NULL, 0, NULL, 0) != UNZ_OK) {
            std::cerr << "Cannot get current file info." << std::endl;
            return false;
        }
       
        if (unzOpenCurrentFilePassword(zipfile, password.empty() ? nullptr : password.c_str()) != UNZ_OK) {
            std::cerr << "Cannot open file inside ZIP archive, possibly wrong password." << std::endl;
           
                std::cout << password << std::endl;
            
            return false;
        }

        std::vector<unsigned char> fileData(fileInfo.uncompressed_size);

      
        int bytesRead = unzReadCurrentFile(zipfile, fileData.data(), fileInfo.uncompressed_size);
        if (bytesRead < 0) {
            std::cerr << "Failed to read file from ZIP archive." << std::endl;
            unzCloseCurrentFile(zipfile);
            return false;
        }

        
        unzCloseCurrentFile(zipfile);

       
        unpackedFiles[filename] = std::move(fileData);
        return true;
    }
};

