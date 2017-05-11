-#ifndef VMTHOOK_H_
-#define VMTHOOK_H_
+/*
+
+	VMTHook - incredibly straight-forward virtual hooking class.
+	Copyright (C) 2017, aixxe. <me@aixxe.net>
+		
+	This program is free software; you can redistribute it and/or modify
+	it under the terms of the GNU General Public License as published by
+	the Free Software Foundation; either version 2 of the License, or
+	(at your option) any later version.
+
+	This program is distributed in the hope that it will be useful,
+	but WITHOUT ANY WARRANTY; without even the implied warranty of
+	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+	GNU General Public License for more details.
+
+	You should have received a copy of the GNU General Public License
+	along with VMTHook. If not, see <http://www.gnu.org/licenses/>.
+
+*/
+#pragma once
 
 #include <cstdint>
 #include <cstddef>
 @@ -9,7 +27,7 @@
 class VMTHook {
 	private:
 		std::uintptr_t** baseclass = nullptr;
-		std::unique_ptr<uintptr_t[]> current_vft = nullptr;
+		std::unique_ptr<std::uintptr_t[]> current_vft = nullptr;
 		std::uintptr_t* original_vft = nullptr;
 		std::size_t total_functions = 0;
 	public:
 @@ -39,7 +57,7 @@ class VMTHook {
 			return reinterpret_cast<Function>(this->original_vft[function_index]);
 		}
 
-		inline const bool HookFunction(void* new_function, const std::size_t function_index) {
+		inline bool HookFunction(void* new_function, const std::size_t function_index) {
 			if (function_index > this->total_functions)
 				return false;
 
 @@ -48,7 +66,7 @@ class VMTHook {
 			return true;
 		}
 
-		inline const bool UnhookFunction(const std::size_t function_index) {
+		inline bool UnhookFunction(const std::size_t function_index) {
 			if (function_index > this->total_functions)
 				return false;
 
 @@ -57,9 +75,7 @@ class VMTHook {
 			return true;
 		}
 
-		inline const std::size_t GetTotalFunctions() {
+		inline std::size_t GetTotalFunctions() {
 			return this->total_functions;
 		}
-};
-
-#endif 
+}; 
