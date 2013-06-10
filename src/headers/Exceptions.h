#pragma once

namespace ThunderSDKDotNet {
	public ref class NotInitializedException : public System::Exception
	{
	public:
		NotInitializedException() : Exception("Platform has not been initialized yet.") {}

		NotInitializedException(System::String^ message) : Exception(message) {}
	};

	public ref class NotSupportedProtocolException : public System::Exception
	{
	public:
		NotSupportedProtocolException() : Exception("This protocol is not supported.") {}

		NotSupportedProtocolException(System::String^ message) : Exception(message) {}
	};

	public ref class InitTaskTrayIconFailedException : public System::Exception
	{
	public:
		InitTaskTrayIconFailedException() : Exception("Failed to initialize the task tray icon.") {}

		InitTaskTrayIconFailedException(System::String^ message) : Exception(message) {}
	};

	public ref class AddTaskTrayIconFailedException : public System::Exception
	{
	public:
		AddTaskTrayIconFailedException() : Exception("Failed to add the task tray icon.") {}

		AddTaskTrayIconFailedException(System::String^ message) : Exception(message) {}
	};
	
	public ref class EmptyStringException : public System::Exception
	{
	public:
		EmptyStringException() : Exception("The given string is empty.") {}

		EmptyStringException(System::String^ message) : Exception(message) {}
	};

	public ref class NoFileNameException : public System::Exception
	{
	public:
		NoFileNameException() : Exception("No file name included in the given path.") {}

		NoFileNameException(System::String^ message) : Exception(message) {}
	};

	public ref class CreateDirectoryFailedException : public System::Exception
	{
	public:
		CreateDirectoryFailedException() : Exception("Failed to create the given directory.") {}

		CreateDirectoryFailedException(System::String^ message) : Exception(message) {}
	};

	public ref class MemoryNotEnoughException : public System::Exception
	{
	public:
		MemoryNotEnoughException() : Exception("Memory is not enough.") {}

		MemoryNotEnoughException(System::String^ message) : Exception(message) {}
	};

	public ref class TaskNotExistException : public System::Exception
	{
	public:
		TaskNotExistException() : Exception("The given task does not exist.") {}

		TaskNotExistException(System::String^ message) : Exception(message) {}
	};

	public ref class MaximumTaskException : public System::Exception
	{
	public:
		MaximumTaskException() : Exception("The task number has reached its maximum.") {}

		MaximumTaskException(System::String^ message) : Exception(message) {}
	};

	public ref class TaskTypeUnknownException : public System::Exception
	{
	public:
		TaskTypeUnknownException() : Exception("The given task type is unknown.") {}

		TaskTypeUnknownException(System::String^ message) : Exception(message) {}
	};

	public ref class ContinueTaskFailedException : public System::Exception
	{
	public:
		ContinueTaskFailedException() 
			: Exception("Failed to continue the given task. Maybe resuming is not supported or the task has failed.") {}

		ContinueTaskFailedException(System::String^ message) : Exception(message) {}
	};

	public ref class PauseTaskFailedException : public System::Exception
	{
	public:
		PauseTaskFailedException() 
			: Exception("Failed to pause the given task. Maybe resuming is not supported or the task has failed.") {}

		PauseTaskFailedException(System::String^ message) : Exception(message) {}
	};

	public ref class TpCrashedException : public System::Exception
	{
	public:
		TpCrashedException() : Exception("TP crashes.") {}

		TpCrashedException(System::String^ message) : Exception(message) {}
	};

	public ref class InvalidTaskException : public System::Exception
	{
	public:
		InvalidTaskException() : Exception("The given task is invalid. Try to call ContinueFromTdFile instead.") {}

		InvalidTaskException(System::String^ message) : Exception(message) {}
	};
}