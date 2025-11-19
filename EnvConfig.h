#pragma once
using namespace System;
using namespace System::IO;

namespace CafeStockConfig {

    public ref class EnvConfig abstract sealed {  // static-like class
    private:
        static String^ cachedConn = nullptr;

    public:
        static String^ GetConnectionString() {
            // return cached value if already loaded

            if (cachedConn != nullptr) return cachedConn;

            String^ path = ".env";
            if (!File::Exists(path)) {
                throw gcnew Exception(".env file not found at " + Path::GetFullPath(path));
            }

            array<String^>^ lines = File::ReadAllLines(path);
            for each (String ^ line in lines) {
                if (line->StartsWith("SQL_CONN=")) {
                    cachedConn = line->Substring(9)->Trim();
                    break;
                }
            }

            if (String::IsNullOrEmpty(cachedConn))
                throw gcnew Exception("Variable SQL_CONN missing in .env file!");

            return cachedConn;
        }
    };
}
