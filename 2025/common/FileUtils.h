#pragma once

#include <string>
#include <vector>

/**
 * @brief Checks if file path is valid
 *
 * @param[in] filePath absolute path string
 * @return true valid
 * @return false invalid
 */
bool IsFilePathValid(const std::string& filePath);

/**
 * @brief Checks if path is valid, opens file for reading and parses content
 * into a vector<string>
 *
 * @param[in] filePath absolute path string
 * @return std::vector<std::string> file content
 */
std::vector<std::string> ReadInputFile(const std::string& filePath);

std::vector<std::string> ReadInputFile(const std::string& filePath,
                                       const char& delimiter);