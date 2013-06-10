// ThunderSDK.net.h

#pragma once

#include <msclr/marshal.h>

namespace ThunderSDKDotNet {
	public enum class TaskStatus
	{
		CONNECTED = 0,
		DOWNLOADING = 2,
		PAUSED = 10,
		SUCCEEDED = 11,
		FAILED = 12,
	};

	public ref class TaskInfo
	{
	public:
		TaskInfo(TaskStatus status, System::UInt64 file_size, System::UInt64 received_size)
			: status(status), fileSize(file_size), receivedSize(received_size)
		{
			if (fileSize != 0)
				completeRate = (float)receivedSize / fileSize;
			else
				completeRate = 0.0f;
		}

		property TaskStatus Status
		{
			TaskStatus get()
			{
				return status;
			}
		}

		property System::UInt64 FileSize
		{
			System::UInt64 get()
			{
				return fileSize;
			}
		}

		property System::UInt64 ReceivedSize
		{
			System::UInt64 get()
			{
				return receivedSize;
			}
		}

		property float CompleteRate
		{
			float get()
			{
				return completeRate;
			}
		}

	private:
		TaskStatus status;
		System::UInt64 fileSize;
		System::UInt64 receivedSize;
		float completeRate;
	};

	public ref class Platform
	{
	public:
		Platform();

		~Platform();

		!Platform();

		void Init();

		int Download(System::String^ file_name, System::String^ download_url, System::String^ ref_url);

		TaskInfo^ GetTaskInfo(int task_id);

		int Pause(int task_id);

		void Resume(int task_id);

		int ContinueFromTdFile(System::String^ path);

		void Stop(int task_id);

	private:
		void ProcessErrorCode(System::UInt32 error_code);

		bool disposed;
		msclr::interop::marshal_context^ context;
	};
}
