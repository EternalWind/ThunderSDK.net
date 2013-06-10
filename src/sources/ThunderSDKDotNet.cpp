// This is the main DLL file.
#include "stdafx.h"

#include "XLDownload.h"
#include "XLError.h"

#include "Exceptions.h"
#include "ThunderSDKDotNet.h"

using namespace System;

namespace ThunderSDKDotNet {
	Platform::Platform()
		: disposed(false)
	{
		context = gcnew msclr::interop::marshal_context();
	}

	Platform::~Platform()
	{
		if (disposed)
			return;

		delete context;

		this->!Platform();
		disposed = true;
	}

	Platform::!Platform()
	{
		bool result = XLUninitDownloadEngine();

		if (!result)
		{
			throw gcnew NotInitializedException();
		}
	}

	void Platform::Init()
	{
		bool result = XLInitDownloadEngine();

		if (!result)
		{
			throw gcnew NotInitializedException("Failed to initialize the platform");
		}
	}

	int Platform::Download(String^ file_name, String^ download_url, String^ ref_url)
	{
		DWORD result;
		LONG task_id;

		// Convert to unmanaged strings.
		LPCTSTR fs = context->marshal_as<LPCTSTR>(file_name);
		LPCTSTR url = context->marshal_as<LPCTSTR>(download_url);
		LPCTSTR ref = context->marshal_as<LPCTSTR>(ref_url);

		result = XLURLDownloadToFile(fs, url, ref, task_id);

		// Clean-up.
		/*if (fs)
			delete fs;
		if (url)
			delete url;
		if (ref)
			delete ref;*/

		ProcessErrorCode(result);

		return task_id;
	}

	TaskInfo^ Platform::GetTaskInfo(int task_id)
	{
		LONG status;
		ULONGLONG file_size;
		ULONGLONG received_size;
		DWORD result;

		result = XLQueryTaskInfo(task_id, &status, &file_size, &received_size);
		ProcessErrorCode(result);

		TaskInfo^ info = gcnew TaskInfo((TaskStatus)status, file_size, received_size);

		return info;
	}

	int Platform::Pause(int task_id)
	{
		LONG new_task_id;
		DWORD result;

		result = XLPauseTask(task_id, new_task_id);
		ProcessErrorCode(result);

		return new_task_id;
	}

	void Platform::Resume(int task_id)
	{
		DWORD result;

		result = XLContinueTask(task_id);
		ProcessErrorCode(result);
	}

	int Platform::ContinueFromTdFile(String^ path)
	{
		LPCTSTR p = context->marshal_as<LPCTSTR>(path);
		LONG task_id;
		DWORD result;

		result = XLContinueTaskFromTdFile(p, task_id);
		
		delete p;

		ProcessErrorCode(result);

		return task_id;
	}

	void Platform::Stop(int task_id)
	{
		XLStopTask(task_id);
	}

	void Platform::ProcessErrorCode(UInt32 error_code)
	{
		/*switch (error_code)
		{
		case XL_SUCCESS:
			break;

		case XL_ERROR_UNINITAILIZE:
			throw gcnew NotInitializedException();
			break;

		case XL_ERROR_UNSPORTED_PROTOCOL:
			throw gcnew NotSupportedProtocolException();
			break;

		case XL_ERROR_INIT_TASK_TRAY_ICON_FAIL:
			throw gcnew InitTaskTrayIconFailedException();
			break;

		case XL_ERROR_ADD_TASK_TRAY_ICON_FAIL:
			throw gcnew AddTaskTrayIconFailedException();
			break;

		case XL_ERROR_POINTER_IS_NULL:
			throw gcnew NullReferenceException();
			break;

		case XL_ERROR_STRING_IS_EMPTY:
			throw gcnew EmptyStringException();
			break;

		case XL_ERROR_PATH_DONT_INCLUDE_FILENAME:
			throw gcnew NoFileNameException();
			break;

		case XL_ERROR_CREATE_DIRECTORY_FAIL:
			throw gcnew CreateDirectoryFailedException();
			break;

		case XL_ERROR_MEMORY_ISNT_ENOUGH:
			throw gcnew MemoryNotEnoughException();
			break;

		case XL_ERROR_INVALID_ARG:
			throw gcnew ArgumentException("The given argument is invalid.");
			break;

		case XL_ERROR_TASK_DONT_EXIST:
			throw gcnew TaskNotExistException();
			break;

		case XL_ERROR_FILE_NAME_INVALID:
			throw gcnew ArgumentException("The given file name is invalid.");
			break;

		case XL_ERROR_NOTIMPL:
			throw gcnew NotImplementedException();
			break;

		case XL_ERROR_TASKNUM_EXCEED_MAXNUM:
			throw gcnew MaximumTaskException();
			break;

		case XL_ERROR_INVALID_TASK_TYPE:
			throw gcnew TaskTypeUnknownException();
			break;

		case XL_ERROR_FILE_ALREADY_EXIST:
			throw gcnew IO::IOException("File already exists.");
			break;

		case XL_ERROR_FILE_DONT_EXIST:
			throw gcnew IO::IOException("File does not exist.");
			break;

		case XL_ERROR_READ_CFG_FILE_FAIL:
			throw gcnew IO::IOException("Failed to read from the given cfg file.");
			break;

		case XL_ERROR_WRITE_CFG_FILE_FAIL:
			throw gcnew IO::IOException("Failed to write to the given cfg file.");
			break;

		case XL_ERROR_CANNOT_CONTINUE_TASK:
			throw gcnew ContinueTaskFailedException();
			break;

		case XL_ERROR_CANNOT_PAUSE_TASK:
			throw gcnew PauseTaskFailedException();
			break;

		case XL_ERROR_BUFFER_TOO_SMALL:
			throw gcnew MemoryNotEnoughException("Buffer size is too small.");
			break;

		case XL_ERROR_INIT_THREAD_EXIT_TOO_EARLY:
			throw gcnew Threading::ThreadStateException("The thread initializes the platform has already exited.");
			break;

		case XL_ERROR_TP_CRASH:
			throw gcnew TpCrashedException();
			break;

		case XL_ERROR_TASK_INVALID:
			throw gcnew InvalidTaskException();
			break;
			
		default:
			break;
		}*/
	}
}